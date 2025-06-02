#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1000000007;


/*
2^6 = 64

Idea probably involves find for each friend node, the possible sets of
special nodes (without car) satisfying the condition (shortest path).

We can do this as such: for each special node and root (1), we calculate
SSSP from it to every other node (at most 7 nodes) so we can query dist.
Then, for each distinct set of friends (2^6 total), go through every node 
x and see if path from 1 to x contains all nodes in the desired set.

To find this, let the set of special nodes be S = {s_1,s_2,...,s_k}, then 
we state that it goes through all the nodes in most optimal path if and 
only if when we sort S by smallest distance from 1, then iff 
dist[1][x] = dist[1][s_1] + dist[s_1][s_2] + ... + dist[s_k][x]. 
Obviously if this satisfies, then its the shortest path since it is 
achievable and equal to dist[1][x] so its most optimal.
If this doesn't satisfy, then it is not possible to go through all nodes
(in a different order) and get most optimal. Consider the path 1->s_1->x.
If we don't go 1->s_1 from the start, we have 1->...->s_1->...->x.
The path 1->...->s-1 must be bigger than dist[1][s_1]. Thus, we've reached 
the same destination using a less optimal path, so the entire path is less
optimal.

Thus, we can create for each node, a set of sets of special nodes that is
satisfiable using this node for all nodes x in O(2^kn). It is now left to 
determine how to get the largest set of special nodes (using each node x 
at most once). 

Hint: Knapsack DP. 

Note again 2^6 = 64. This is classic knapsack using bits. For each node, 
there are at most 2^6 sets. For each of them, consider all other 2^6 sets
(all represented as masks). Then, we take it or don't take it. If we take 
it then we OR the mask. This is O(2^{2k}n) = 10^4 * 64^2 = 40960000 which
probably passes 3 seconds.


*/

map <pi,int> dist;

bool cmp(int x, int y){
    return dist[{0,x}] < dist[{0,y}];
}

void solve(){   
    int n,m;cin>>n>>m;
    
    vi aj[n];
    rep(i,0,m){
        int x,y;cin>>x>>y;
        x--;y--;
        aj[x].pb(y);
        aj[y].pb(x);
    }

    int b;cin>>b;
    int ff[b];
    rep(i,0,b){
        cin>>ff[i];
        ff[i]--;
    }
    
    int k;cin>>k;
    int p[k];
    rep(i,0,k){
        cin>>p[i];
        p[i]--;
        
    }
    
    
    vi f;
    rep(i,0,b){
        bool ok = true;
        rep(j,0,k){
            if(i==p[j]){
                ok = false;
            }
        }
        if(ok) f.pb(ff[i]);
    }
    b = f.size();
    
    rep(i,0,k){
        p[i] = ff[p[i]];
    }
    
    rep(i,0,k){
        
        rep(j,0,n){
            dist[{p[i],j}]=1e9;
        }
        dist[{p[i],p[i]}]=0;
        queue<int>q;
        q.push(p[i]);
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto y : aj[x]){
                if(dist[{p[i],y}]==1e9){
                    dist[{p[i],y}]= dist[{p[i],x}]+1;
                    q.push(y);
                    
                }
            }
        }
    }


    rep(j,0,n){
        dist[{0,j}]=1e9;
    }
    dist[{0,0}]=0;
    queue<int>q;
    q.push(0);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto y : aj[x]){
            if(dist[{0,y}]==1e9){
                dist[{0,y}]= dist[{0,x}]+1;
                q.push(y);
                
            }
        }
    }
    vi s[n];
    rep(mask,0,(1<<k)){
        vi v; v.pb(0);
        rep(i,0,k){
            if(((1<<i) & mask)){
                v.pb(p[i]);
            }
        }
        sort(v.begin(),v.end(),cmp);
        rep(fr,0,b){
            int i = f[fr];
            int sum = 0;
            v.pb(i);
            rep(j,0,v.size()-1){
                sum+=dist[{v[j],v[j+1]}];
            }
            v.pop_back();
            if(sum == dist[{0,i}]){
                s[i].pb(mask);
            }
        }
    }

    int dp[(1<<k)][b+1];
    memset(dp,0,sizeof(dp));
    rep(fr,1,b+1){
        int i = f[fr-1];
        rep(l,0,(1<<k)){
            dp[l][fr] = dp[l][fr-1];
        }
        rep(j,0,s[i].size()){
            dp[s[i][j]][fr] = 1;
            rep(l,0,(1<<k)){
                dp[(s[i][j]|l)][fr] |= dp[l][fr-1];
            }
        }
 
    }
    int ans = 0;
    rep(l,0,(1<<k)){
        if(dp[l][b]){
            int cnt = 0;
            rep(i,0,k){
                if(((1<<i) & l)){
                    cnt++;
                }
            }
            ans = max(ans,cnt);
        }
        
    }
    cout<<k-ans<<endl;
    

    
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