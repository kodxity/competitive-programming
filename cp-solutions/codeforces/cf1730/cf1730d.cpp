#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using orderedMultiset = tree<T ,null_type,std::less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
ll MOD = 1000000007;
 

/*
Note t<=10 and there are 10^5 queries, so we can't do much online.

We can precalculate the maximum prefix that is possible. That is, for
some length x s[1...x] = s[n-k...n] where k<x and x-k<=10. Then find the
corresponding t that makes this satsfied. We can fix x, then go through
each x-k from 1 to 10, then use hashing to see if they're equal, and 
store each possible t string that goes along with it. During query, we
can just see for each t the maximum length that is satisfied by this t
when added to the end. 

TLE, try instead of using substring as map key, try store as hash values
for small time optimization (so O(1) lookup rather than O(length)), and
we may also leverage gp hash tables if needed.

wait... TLE cause 1e6 bound for hsh array instead of 2e5 im dumb...

*/

mt19937 RNG((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll M = (1LL << 61) - 1; // large prime for mod
const ll P = uniform_int_distribution<ll>(0, M - 1)(RNG); // random base
ll hsh[1000005]={0}; // LENGTH OF STRING 
vector <ll> pw = {1LL};
__int128 mul(ll a, ll b) { return (__int128)a * b; }
ll mod_mul(ll a, ll b) { return mul(a, b) % M; }
void calchash(string s){
    // precalc pow
    
    hsh[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			hsh[i + 1] = (mul(hsh[i], P) + s[i]) % M;
		}
}
long long gethash(int start, int end) { // inclusive: string [start...end]
	ll raw_val =
		    hsh[end + 1] - mod_mul(hsh[start], pw[end - start + 1]);
		return (raw_val + M) % M;
}

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

gp_hash_table<ll, int, chash> mp;

void solve(){   
    string s;
    cin>>s;
    while (pw.size() < max(10,int(s.size()))) {
        pw.push_back(mod_mul(pw.back(), P) % M);
    }
    int n = s.size();
  
    calchash(s);

    rep(x,0,n){
        if(gethash(0,x-1) == gethash(n-x,n-1)){
            rep(j,1,11){
                mp[gethash(x,x+j-1)] = max(mp[gethash(x,x+j-1)],x+j);
            }
        }
    }
    ll hashval[11];
    rep(i,1,min(11,n+1)){
        mp[gethash(0,i-1)]=max(mp[gethash(0,i-1)],i);
        hashval[i] = gethash(0,i-1);
      
    }
    int q;cin>>q;
    while(q--){ 
        string t;cin>>t;
        int idx = -1;
        calchash(t);
        rep(i,0,t.size()){
            ll t1 = gethash(0,i);
            int ans = mp[t1];
            if(n<=10){
                string a = s+t.substr(0,i+1);
                
                rep(i,0,a.size()-1){
                    if(a.substr(0,i+1) == a.substr(a.size()-i-1,i+1)){
                        ans = max(ans,i+1);
                    }
                }
            }
            
            if(idx != -2){
             
                if(idx == -1 && mp[t1]==n){
                    idx = 0;
                }
                else if(idx != -1){
                    if(t[idx]==t[i]){
                        
                        ans = n+idx+1;
                        
                        idx++;
                    }
                    else{
                        idx = -2;
                    }
                }
            }
            // can brute force this
            rep(j,1,i+1){
                if(hashval[(i+1)-j] == gethash(j,j-1+(i+1)-j)){
                    ans = max(ans,(i+1)-j);
                }
            }
      
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1; 
   
    // cin>>t;

    while(t--){
        solve();
    }

    return 0;
}; 