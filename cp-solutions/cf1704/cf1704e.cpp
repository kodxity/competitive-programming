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
O(n^2) passable.

For each round, erase one node (no in edges), keep doing for n rounds and
add up total time.
Imagine if the problem is restricted such that every node has a[i]>0. 
Then, this is easy because for every node that is not a leaf (no in edges), 
it will always be positive since it gives away one, but recieves at least 1 
since there is at least one positive node that points to this. However if 
this node was a leaf it may go to 0. 
Thus, we can just do n rounds, and each round we delete the node has no in
edge, and has the least value, as this node x will be the first to disappear.
Then, we can add val[x] to time. Then, we erase this node and all its edges
and update indeg accordingly. Then, we can update the val of each node in O(1)
using formula time * (indeg[i]-1) since in every second, it will recieve 1 from
all nodes pointing to it (indeg), and give away 1, assuming that all nodes have
a positive value as previously stated. Then, we do this for n rounds at most and
every node will be erased.

The problem arises that not every node is positive, some can be 0, and it will
be less easy to deal with (as seen by sample 3), and you have to delay stuff and
account for distance of node to the nearest positive node, etc, and it becomes
a confusing mess on how to deal with this (even at O(n^2)).

Hint: To solve this issue, I claim that we can turn any graph into a graph where
all nodes have positive value, in at most n time. If this is possible, the solution
becomes solvable, as descrbied previously. 
Note if a positive node connects to another node, then they will stay connected no
matter what (until the no in edge node runs out ofc, but the nodes will still be 
continuously connected). Thus, at each time a positive node will branch out to the 
node it points to. The longest distance between any two nodes is n, so in at most
O(n) time, every node will be connected to each other (minus the nodes we've erased
in this process but we don't care about it). Thus, every node will be positive and 
we can proceed with the above solution. 
Brute forcing to time n can be simulated in O(n^2), so total is O(n^2). 

WA because it will get big and 
*/


void solve(){   
    int n,m;cin>>n>>m;
    
    ll val[n];
    rep(i,0,n){
        cin>>val[i];
    }

    ll indeg[n]={0};
    ll del[n]={0};
    vi aj[n];
    rep(i,0,m){
        int x,y;cin>>x>>y;
        x--;y--;
        indeg[y]++;
        aj[x].pb(y);
    }
    int vis[n+1]={0};
    queue <int> q;
    // insert all nodes with indegree 0 first
    rep(i,0,n){ 
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    vi sorted; // ans
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(vis[x]){
	        continue;
        }
        vis[x]=1;
        sorted.pb(x); // process and erase curr node
        rep(i,0,aj[x].size()){
            indeg[aj[x][i]]--; // indegree of neighbour subtract 1
            if(indeg[aj[x][i]] == 0){ // indegree of neighbour = 0
                q.push(aj[x][i]); // process this node next
            }
        }
    }
    rep(i,0,n){
        for(auto x : aj[i]){
            indeg[x]++;
        }
    }
    ll ans = 0;
    // brute force n rounds
    ll cnt = 1e18;
    rep(r,0,n){
        cnt = 0;
        rep(i,0,n){
            cnt += val[i];
        }
        if(cnt == 0){
            cout<<ans<<"\n";
            return;
        }
        ll ad[n]={0};
        rep(i,0,n){
            if(del[i]==0){
                if(val[i]>0){
                    val[i]--;
                    for(auto x : aj[i]){
                        ad[x]++;
                    }
                }
                else if(indeg[i]==0){
                    del[i]=1;
                    for(auto x : aj[i]){
                        indeg[x]--;
                    }
                }
            }
            
        }
        cnt = 0;
        rep(i,0,n){
            val[i]+=ad[i];
            
        }
        ans = r+1;
        
    }
    int endnode = 0;
    rep(i,0,n){
        if(aj[i].size()==0){
            endnode = i;
        }
    }

    

    rep(i,0,n){ 
        // direct simulation leads to ll overflow.
        // consider how each node contributes to total sum

        ll dp[n]={0};
        dp[i]=1;
        rep(j,0,n){
            for(auto x : aj[sorted[j]]){
                dp[x]+=dp[sorted[j]];
                dp[x]%=MOD;
            }
        }

        ans += dp[endnode]*val[i];
        ans %= MOD;
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