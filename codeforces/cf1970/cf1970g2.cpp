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
We want the two components (complexes) to be as even as possible in terms of 
number of nodes, since for example, 3^2 + 3^2 < 1^2 + 5^2.
Note if we already have 1 connected component, we don't need to add any more
edges (it wull always suboptimal) because we want to choose the "unite" node 
properly. If we make something a cycle when it was originally not, this will
only worsen our chances of an optimal answer as it restricts us more.
If there are k components, the most optimal way is to add k-1 edges so that
they are all connected, and go from there, since similarily, adding more edges 
will create more cycles which is suboptimal. 
Since n,m <= 300, we may try brute forcing the "unite" edge, for every edge, we
can simulate by deleting this edge and connecting all other edges. Then, we 
check if the two nodes can still connect without this edge. If it can, we know 
this can't be the "unite" edge by conditions. We can achieve this all with DSU.
If this can be a "unite" edge, we can go proceed with construction. 
To construct the optimal two cc (such that there sizes are similar as possible),
this seems like a classic problem, but with no easy approaches. Essentially the
problem turns into: we are given a set of values, and we want to split them into
two teams such that their sums are as similar as possible.
However, one simple approach is to just brute force the valid construction using
knapsack dp. Since there are at most 300 nodes, we can do knapsack in O(n^2) and 
still pass with total O(mn^2). 
Thus, we can just simply run knapsack dp, then find the possible value closest
to n/2 after dp, which is our answer for making the ith edge the "unite" edge. 
Also note we must add the edges we must add to make everything connected. 
When choosing ith edge as "unite", the number of edges we must add is (# of cc)-2
because we didn't add the ith edge (but we assume they are in same cc), and we
always add (# of cc)-1 edges. 
Then, we must also consider the case where the "unite" edge is an edge we are
going to add to the graph (not in the original graph) in order to connect cc's.
This case is just we add all edges into dsu, then just do the same process of
knapsack dp based on the cc's we made, but instead of (# of cc)-2 it's 
(# of cc)-1 since we currently, the all cc's are what they are (really
disconnected, not "fake" disconnected due to "not adding the unite edge").


*/

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
    ll n,m,c;
    cin>>n>>m>>c;
    vector<pii>e;

    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        x--;y--;
        e.pb({x,y});
    }

    ll ans = 1e18;

    rep(i,0,m){
        DSU dsu(n);
        rep(j,0,m){
            if(i != j){
                auto [x,y] = e[j];
                dsu.unite(x,y);
            }
        }
        if(dsu.find(e[i].F)==dsu.find(e[i].S)){ // already connected
            continue;
        }
        set<int>st;
        rep(j,0,n){
            st.insert(dsu.find(j));
        }
        vi v;
        for(auto it : st){
            v.pb(dsu.getsize(it));
        }
        // knapsack
        int dp[n+1]={0};
        dp[0]=1;
        rep(j,0,sz(v)){
            for(int l = n;l>=0;l--){
                if(l+v[j] <= n){
                    dp[l+v[j]] |= dp[l];
                }
            }
        }

        for(ll j = n/2;j>=1;j--){
            if(dp[j]){
                ans = min(ans, j*j + (n-j)*(n-j) + (sz(st)-2) * c);
                break;
            }
        }
    }


    DSU dsu(n);
    rep(j,0,m){
        auto [x,y] = e[j];
        dsu.unite(x,y);
        
    }
    set<int>st;
    rep(j,0,n){
        st.insert(dsu.find(j));
    }
    vi v;
    for(auto it : st){
        v.pb(dsu.getsize(it));
    }
    // knapsack
    int dp[n+1]={0};
    dp[0]=1;
    rep(j,0,sz(v)){
        for(int l = n;l>=0;l--){
            if(l+v[j] <= n){
                dp[l+v[j]] |= dp[l];
            }
        }
    }

    for(ll j = n/2;j>=1;j--){
        if(dp[j]){
            ans = min(ans, j*j + (n-j)*(n-j) + (sz(st)-1) * c);
            break;
        }
    }

    if(ans == 1e18){
        cout<<-1<<"\n";
        return;
    }
    cout<<ans<<"\n";




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