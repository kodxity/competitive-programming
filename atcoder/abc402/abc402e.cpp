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
ll MOD = 998244353;
 

/*

*/


void solve(){   
    int n,x;
    cin>>n>>x;
    long double dp[n][x+1];
    memset(dp,0,sizeof(dp));
    rep(i,1,n+1){
        int c;
        long double s,p;
        cin>>s>>c>>p;
        p/=100;
        int tc = 1;
        long double pp = 1;
        long double ans = 0;
        rep(j,1,x+1){
            while(tc*c<=j){
                ans += pp*p*s;
                pp *= 1-p;
                dp[i][j-tc*c] = max(dp[i][j-tc*c],dp[i-1][j]+ans);
                tc++;
            }
        } 
        
    }
    long double ans = 0;
    rep(i,0,x+1){
        ans = max(ans,dp[n][i]);
    }
    cout<<fixed<<endl;
    cout<<ans<<endl;
    
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