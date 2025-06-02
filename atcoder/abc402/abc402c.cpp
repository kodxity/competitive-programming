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
    int n,m;cin>>n>>m;
    vi v[m];
    rep(i,0,m){
        int k;cin>>k;
        rep(j,0,k){
            int u;cin>>u;
            v[i].pb(u);
        }
    }
    int idx[n+1]={0}; 
    vi a;
    rep(i,0,n){
        int u;cin>>u;
        a.pb(u);
        idx[u]=i;
    }

    int pre[n]={0};
    rep(i,0,m){
        int mx = 0;
        rep(j,0,v[i].size()){
            mx = max(mx, idx[v[i][j]]);
            
        }
        pre[mx]++;
    }

    rep(i,0,n){
        if(i>0) pre[i]+=pre[i-1];
        cout<<pre[i]<<"\n";
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