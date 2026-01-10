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
typedef pair<int, int> pii;
typedef vector<int> vi;
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
ll MOD = 998244353;
 

/*
No clue how to approach this. 1e4 + 1e6 constraint is very sus but I was just
thinking about O(nsqrt(mx)) solution or smth lol.

Hint: Let k be the answer, then sum of a - sum of b differ by a multiple of k. 
This is at most 1e4 * 1e6 = 1e10. We can then find all divisors of this sum 
and brute force all possible k, note that there are at most ~2500 divisors 
for a number <= 1e10.

Then, we may simply brute force by seeing if the current k matches array b
after modding. The fastest way to do this is sorting in O(nlogn). Thus, total
time edges around 1e8 operations which is sus but it might work so.
*/





void solve(){   
    int n;cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    ll suma = 0;
    ll sumb = 0;
    rep(i,0,n){
        cin>>a[i];
        suma+=a[i];
    }
    rep(i,0,n){
        cin>>b[i];
        sumb+=b[i];
    }
    sort(all(a));
    sort(all(b));
    if(a==b){
        cout<<1000000000<<"\n";
        return;
    }
    ll diff = suma-sumb;
    for(ll i = 1;i*i<=diff;i++){
        if(diff%i==0){
            ll x = i;
            bool yes = 1;
            vi as;
            rep(j,0,n){
                as.pb(a[j]%x);
            }
            sort(all(as));
            rep(j,0,n){
                if(as[j]!=b[j]){
                    yes = 0;
                    break;
                }
            }
            if(yes){
                cout<<x<<"\n";
                return;
            }
            
            x = diff/i;
            yes = 1;
            as.clear();
            rep(j,0,n){
                as.pb(a[j]%x);
            }
            sort(all(as));
            rep(j,0,n){
                if(as[j]!=b[j]){
                    yes = 0;
                    break;
                }
            }
            if(yes){
                cout<<x<<"\n";
                return;
            }
        }
        
        
    }

    cout<<-1<<"\n";





}


int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1; 
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
};  