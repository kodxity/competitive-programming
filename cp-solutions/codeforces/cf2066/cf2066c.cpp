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
ll MOD = 1e9+7;
 

/*

*/


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
    rep(i,0,n){
        cin>>v[i];

    }

    map<int,int>dp;
    dp[0]=1;
    int pre=0;
    rep(i,0,n){
        int prev = pre;
        pre ^= v[i];
        dp[prev] = add(mult(3,dp[prev]), mult(2,dp[pre]));
    }
    ll ans = 0;
    for(auto x : dp){
        ans = add(ans,x.S);
    }
    cout<<ans<<endl;
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