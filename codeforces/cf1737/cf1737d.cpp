#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1000000007;


/*
O(n^2) is possible. We want most optimal edges so eliminate all suboptimal 
multiedges.

At most n^2 edges.

A wizard operation disconnecting u,v, then connecting u,t can be viewed as
creating a new edge of weight 2*w connecting u,t since w time for build 
plus w time for going through it. In similar fashion, we can go through 
all neighbours x of t and connect u to x with weight 3*w,  and so on. 

I state that for every edge from n, if we connect n to every other node 
using the above idea (if node x is dist d away from n, weight is (d-1)w),
then answer is the shortest path if we then do normal dijkstra. Obviously
the build of each edge is valid. Note if we go from n to x as optimal, we
don't ever need to take any edge from n to anything else or vice versa, since
we already reached n and thus won't need to go from or to n. 

It is left to do this in O(n^2).

Oops just checked editorial apparently O(n^3) passes. Ig so since its 4 sec.

This is thus trivial. For each edge (at most n^2), do BFS and add edges
in O(n). Then, run shortest path algorithm like warshall

This approach fails test case 3 which makes repeated self loops of 22 to
optimize answer. There is no easy appraoch to this.

Hint: it is always optimal to make edge between 1 and n in the end.
Proof: Say we have the answer of the optimal path from 1 to n consisting
of k edges. Pick the smallest of all edges (let weight be w). Then, sum
of weights of edges >= kw, and there exists a possible construction costing
kw where we repeatedly do operation on edge k times until it connects 1
and n.

Following this and the idea we see in test case 3, we note that the optimal
answer will always be kw for some w. This w may originate from one of the
original weights since doing operations must always increase weights. Thus,
we go throught all edge weights and check if this w yields the optimal 
answer. 
Let there be some edge x,y. Let's create a minimum spanning tree containing 
1,n,x,y (where all edges are length 1). Then, I state the optimal answer is
just the number of edges in the tree * w for this specific weight. 
Proof (to lazy but will give outline): It is possible to achieve this cost,
and this is the minimum cost since if we don't make MST we can't connect
1 to n using this edge, and for this MST it will at least take that many edge.

Thus, for each edge (n^2 of them), we try to find the MST. To find the MST,
either its 1->x->y->n (or vice versa) or 1->z,n->z, then z->x or z->y for some
not z. Whichever produces the smallest distance is the best MST.
We can precompute shortest distance of two nodes before hand.
First case is dist(1,x)+1+dist(y,n).
Second case is for every z, dist(1,z)+dist(n,z)+dist(z,x).
Can be done in O(n^3) brute force every z.
Note for second case, we must add a self loop or else it doesn't work, so +1.
*/

void solve(){   
    int n,m;cin>>n>>m;
    long long dist[n][n];
    long long d1[n][n];
    vi aj[n];    
    rep(i,0,n){
        rep(j,0,n){
            dist[i][j] = 1e18;    
            d1[i][j] = 1e18;     
            if(i==j) d1[i][j]=0;
        }
    }

    rep(i,0,m){
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        
        if(dist[x][y] == 1e18){
            aj[x].pb(y);
            aj[y].pb(x);    
        }
        if(w<dist[x][y]){
            dist[x][y] = w;
            dist[y][x] = w;
            d1[x][y]=1;
            d1[y][x]=1;
        }
    }
    for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				long long new_dist = d1[i][k] + d1[k][j];
				if (new_dist < d1[i][j]) {
					d1[i][j] = d1[j][i] = new_dist;
				}
			}
		}
	}
    ll ans = 1e18;
    rep(i,0,n){
        rep(j,0,n){
            if(dist[i][j]!=1e18){
                ll sz;
                sz = min(d1[0][i]+d1[j][n-1]+1, d1[0][j]+d1[i][n-1]+1);
                rep(l,0,n){
                    sz = min(sz, d1[0][l] + d1[n-1][l] + min(d1[l][i],d1[l][j])+1 +1);
                }
         
                ans = min(ans, sz * dist[i][j]);
            }
        }
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