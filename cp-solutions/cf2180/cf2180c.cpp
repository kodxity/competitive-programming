// what's another death?
// send the ocean my apologies

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define rep(i,a,b) for (int i=a; i<(b); i++)
#define repv(i,a,b) for (int i = (b)-1; i >= a; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 
const ll INF = (1LL<<60);


/*
Want it so that for each bit, it's equal to n for xor (number of bits is odd) while
keeping the sum max. 
Go through bits of n, for each bit that has 0, define k or k-1 bits as 1 (k if k is even).
For each bit that has 1, define k or k-1 bits as 1 (k if k is odd)

For odd cases: find maximum sum of two numbers whose xor is n.
Take 1st and 2nd bit of the number. If it only has 1 bit we just do 0.
Then, for all bits after the second bit we let x =  111... - (n & 111...) and then the two 
numbers are 2^b_1 + x and 111.. where the starting 1 is at 2^b_2 where b_1, b_2 are the 1st
and 2nd bits respectively.

nvm previous ideas are wrong. Consider greedy strategy where we start with all 1111... = 2^31-1
for all numbers, then we consider at each bit, which elements we NEED to remove this bit from.
Note for k = odd, all elments can be n and we're done. For k = even, for each bit if n = 1 on that
bit it is sufficient to remove this bit from exactly 1 element. This can be any element.
Then, if n = 0 on this bit, we must remove this bit from all element who we've never removed a bit 
from using the n = 1 operation, as if we don't do this, these elements will be > n. Then, sometimes
the number of bits we removed is odd, which is bad, so we must remove an extra bit from an element
where we previously removed from.

Overall not hard, just kinda cooked cause my thinking was wrong and I underestimated. But good cause
it gave me an excuse to practice writing a validator and tweaking testcase generator
*/


void solve() {
    int n,k; cin>>n>>k;
    vi ans(k); 
    rep(i,0,k){
        ans[i] = n;
    }
    if(k%2==0){
            int it = 0;
            rep(i,0,k){
                ans[i] = (1LL<<31)-1;
            }
           
            repv(i,0,31){
                if((n&(1<<i))==0){
                    if(it <= k-1){
                                
                        if((k-it)%2){
                            ans[it-1] -= (1<<i);
                        }
                        rep(j,it,k){
                            ans[j] -= (1<<i); 
                        }
                    }
                }
                else{
                    ans[min(k-1,it)] -= (1<<i);
                    it++; 
                    
                           
                }
            }
            


    }
    /*
    for(int i = 30;i>=0;i--){
        int cnt = 0;
        vi v;
        rep(j,0,k){
            if(ans[j]+(1<<i)<=n){
                cnt++;
                v.pb(j);
            }
        }
        if((1<<i)&n){
            if(cnt%2){
                rep(j,0,sz(v)){
                    ans[v[j]] += (1<<i);
                }
            }
            else{
                rep(j,0,sz(v)-1){
                    ans[v[j]] += (1<<i);
                }
            }
        }
        else{
                
            if(cnt%2==0){
                rep(j,0,sz(v)){
                    ans[v[j]] += (1<<i);
                }
            }
            else{
                rep(j,0,sz(v)-1){
                    ans[v[j]] += (1<<i);
       
                }
            }
        }
    }
    */
    rep(i,0,k){
        cout<<ans[i]<<" ";
    }
    cout<<nl;

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}

