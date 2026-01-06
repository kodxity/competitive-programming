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
I read the editorial cause I was confused: Assume there are car at x and y 
where x<y.
Two cars are irrelevent iff x goes L and y goes R. 
Two cars are destined iff x goes R and y goes L.
The challenge of this problem is to somehow consider and make all conditions 
satisfy using some graph relationships.

Think of when it's NO. Note that if a node x is facing Left, and it has some
relationship (1 or 2) with another node y, then node y must always face right
(check by considering 2 cases). Thus, if the relationships does not match
a bipartite coloring, we automatically return 0. Else, we can assign direction
the node faces for all nodes.

However, we still have to sort the nodes in some order so that the relationships
are satisfied. We can consider the following 4 cases:
If x face left and c = 1, x < y.
If x face left and c = 2, y < x.
If x face right and c = 1, y < x.
If x face right and c = 1, x < y.
If these relationships satisfy without contradicting each other, we have a valid
sequence. Note this is the same as topological sorting.
When x < y, we can assign a directed edge x -> y. 
When y < x, we can assign a directed edge y -> x.
Then, if we can find a topological sort, we can just print out the answer in that
order (since we already assigned direction we don't have to worry about it). Else,
if there is some cycle and the relationship can't satisfy, we output "NO".

*/



vector<pii> aj[200005];
vi adj[200005];
int vis[200005]={0};

bool invalid = 0;

void dfs(int n){
    for(auto [x,c] : aj[n]){
        if(!vis[x]){
            vis[x] = 3-vis[n];
            dfs(x);
        }
        else{
            if(vis[x]==vis[n]){ // bad
                invalid = 1;
            }
        }
        if(vis[n]==1){ // left
            if(c==1){
                adj[n].pb(x);
            }
            else{
                adj[x].pb(n);
            }
        }
        else{ // right
            if(c==1){
                adj[x].pb(n);
            }
            else{
                adj[n].pb(x);
            }
        }
    }
}


void solve(){   
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
        int c,x,y;
        cin>>c>>x>>y;
        x--;y--;
        aj[x].pb({y,c});
        aj[y].pb({x,c});
        
    }
    rep(i,0,n){
        if(!vis[i]){
            vis[i]=1;
            dfs(i);
        }
    }
    

    if(invalid){
        cout<<"NO\n";
        return;
    }

    // topological sort

    vector<int> in_degree(n);
	for (const vector<int> &nodes : adj) {
		for (int node : nodes) { in_degree[node]++; }
	}

	queue<int> queue;
	for (int i = 0; i < n; i++) {
		if (in_degree[i] == 0) { queue.push(i); }
	}
	vector<int> top_sort;
	while (!queue.empty()) {
		int curr = queue.front();
		queue.pop();
		top_sort.push_back(curr);
		for (int next : adj[curr]) {
			if (--in_degree[next] == 0) { queue.push(next); }
		}
	}
    int ans[n];
	if(top_sort.size() != n){
        cout<<"NO\n";
        return;
	} 
    rep(i,0,n){
        ans[top_sort[i]]=i;
    }
    cout<<"YES\n";
    rep(i,0,n){
        cout<<(vis[i] == 1 ? "L" : "R")<<" "<<ans[i]<<"\n";
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