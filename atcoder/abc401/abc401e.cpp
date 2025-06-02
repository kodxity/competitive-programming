#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1e9+7;

class DSU{
    private:
        vector<int>parents;
        vector<int> sizes;
    public:
        DSU(int size): parents(size),sizes(size,1){
            for(int i = 0;i<size;i++){
                parents[i]=i;
            }
        }

        int getsize(int x){
            return sizes[find(x)];
        }

        int find(int x){
            return parents[x] == x ? x : (parents[x] = find(parents[x])); 
        }

        bool unite(int x, int y){
            int xr = find(x);
            int yr = find(y);
            if (xr == yr){
                return false;
            }

            if(sizes[xr] < sizes[yr]){
                swap(xr,yr);
            }
            sizes[xr] += sizes[yr];
            parents[yr]=xr;
            return true;
        }
};


void solve(){   

    int n,m;cin>>n>>m;
    vi aj[n+1];
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        aj[x].pb(y);
        aj[y].pb(x);

    }
    int ans = 0;
    int vis[n+1]={0};
    DSU dsu(n+1);
    rep(i,1,n+1){
        if(vis[i]){
            ans--;
        }
        for(auto x : aj[i]){
            if(x>i){
                if(vis[x]==0){
                    vis[x]=1;
                    ans++;
                }
            }
            else{
                dsu.unite(x,i);
            }
            
        }
      
        if(dsu.getsize(1)==i){
            cout<<ans<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
        
    }
}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int t=1; 
 
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}; 