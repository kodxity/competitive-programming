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
The answer must be always at least n = 2^p, since this occurs the
first time there is a values >= 2^p on the path. Since 2n-1>=2^p,
there must exist at least one value >= 2^p in tree, so such a path
always exists.

We can always find a construction exactly for n = 2^p:
Pick and arbituary root and set its value to 2^p.
Inductive step: Let any path from root to node/edge be at most
2^p. More specifically, let path from root to edge be < 2^p and
path from root to node be exactly either 0 or 2^p.
Now we add a new {edge, node} pair. 
In path from root to this edge, we previously ended on a node,
so our current path value is either 0 or 2^p. 
If its 0, we assign edge = cnt, node = 2^p+cnt where cnt is
some arbituary number < 2^p. This way, path xor to edge is cnt
and path xor to node is 2^p, so condition satisifies.
If its 2^p, we assign edge = 2^p+cnt, node = cnt, so path xor
to edge is cnt and path xor to node is 0, so condition satisfies.

We can repeat this two coloring process to get a valid construction.
To assign a valid value, we just increase cnt each time we recieve a
new {edge,node} pair to avoid duplicates.
*/

vi aj[(1<<17)];
int vis[(1<<17)]={0};
map<pi,int>mp;
int ans[(1<<17)];
int cnt = 0;
int two = 0;
int color[(1<<17)];
void dfs(int n){
    vis[n]=true;
    for(auto x : aj[n]){
        if(!vis[x]){
            cnt++;
            color[x]=1-color[n];
            if(color[n]==0){
                mp[{n,x}]=two+cnt;
                mp[{x,n}]=two+cnt;
                ans[x]=cnt;
                
            }
            else{
                mp[{n,x}]=cnt;
                mp[{x,n}]=cnt;
                ans[x]=two+cnt;
            }
            dfs(x);           
        }
    }
}


void solve(){   
    int n;cin>>n;
    rep(i,0,(1<<n)){
        vis[i]=0;
        aj[i].clear();
    }
    cnt = 0;
    two=(1<<n);
    vector<pi>v;
    rep(i,0,(1<<n)-1){
        
        int x,y;
        cin>>x>>y;
        x--;y--;
        v.pb({x,y});
        aj[x].pb(y);
        aj[y].pb(x);
    }
    ans[0]=(1<<n);
    color[0]=0; // 2^p
    dfs(0);
    
    cout<<1<<"\n";
    rep(i,0,(1<<n)){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    rep(i,0,(1<<n)-1){
        cout<<mp[v[i]]<<" ";
    }
    cout<<"\n";

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