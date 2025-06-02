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
typedef tuple<int,int,int> tiii;
typedef vector<int> vi;
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
ll MOD = 998244353;


/*

*/

ll qexp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}

ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}  

ll mult(ll x, ll y)
{
    return (x%MOD * 1ll * y%MOD) % MOD;
}
void solve(){   
    int n;cin>>n;
    vi v(n);
    int val = 0;
    rep(i,0,n){
        cin>>v[i];
        val = gcd(val,v[i]);
    }
    int cnt = 0;
    rep(i,0,n){
        if(v[i]==val){
            cnt++;
        }
        v[i]/=val;
    }
    if(cnt){
        cout<<n-cnt<<"\n";
        return;
    }
    int dp[5005];
    rep(i,0,5005){
        dp[i]=1e9;
    }
    rep(i,0,n){
        dp[v[i]]=1;
        rep(j,1,5001){
            dp[gcd(j,v[i])]=min(dp[gcd(j,v[i])],dp[j]+1);
        }
    }
    cout<<dp[1]-1+n-1<<"\n";


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