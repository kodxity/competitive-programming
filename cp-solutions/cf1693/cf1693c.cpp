// what's another death?
// someday ill get it :>

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define rep(i,a,b) for (int i=a; i<(b); i++)
#define repv(i,a,b) for (int i = (b)-1; i >= a; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 
const int INF = 1e9+5;

// DEBUG
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


/*
If the graph didn't contain cycles, then its DAG. Then, we just do dp on it where each node goes can go to the ith max 
distance node if they block off the last k-ith nodes where k is the total number of neighbors.
However, we have cycles which is more complicated. In the final path, we want to disconnect all cycles in the graph since
if we were to keep a cycle going then it's infinity since we're assuming there is a path that can reach that cycle. However,
note we don't have to eliminate ALL cycles. We can possibly eliminate an earlier edge that is connected to this cycle, so that 
we can never reach this cycle. This may be a good strategy if we have multiple cycles and we don't want to eliminate an edge
from all those cycles, so we just eliminate the earlier edge connected to this cycle so that all those cycles are not reached.
We can do some operations to make sure we don't have a cycle. First run BFS to find the shortest path. Then, we know that
whenever we reached a node that we already reached before using an edge, then this edge is always sub-optimal. This is because

Just looked at editorial cause I have no clue how to deal with cycle cases + which edge to delete for the cycle.
TC 12 fail was due to the below test case:
6 13
1 5
5 4
4 2
2 6
3 6
4 5
1 5
1 4
3 5
3 4
1 3
5 6
2 3

My Output: 5. Correct Output: 4.
This is because I am "removing" too many edges since I assume they're useless, when in fact they might not be useless since
deletion of earlier edges may cost more.

Editorial uses Shortest Path (Dijkstra) ideas. 
The main issue stopping us from running dp is due to cycles. However, what if there is a way to still find dp value by using
shortest path? I didn't think about going backwards using dijkstra methods too deeply since I thought the problem was just the
same and we're not doing anything, but I guess it's the thought that counts. So we let dp[x] = shortest distance from x to n.
Then go backwards. At each node, the only rule is that we want to always go to the node where we think the answer is the worst. 
However, the problem is that at each node, we can't predict what each of its neighbor's dps are, since we can't predit the future
and some dps depend on other, so at any time we can't get the full array of all dp values, then sort them to determine the best 
value (thus the reason why we were trying to eliminate cycles). 
However, the idea is that we don't have to actually get this array, since for each edge, the only thing we need to know is its 
index in the array, which we can achieve by the monotonic nature of dijkstra. 
For some y -> x to be valid (we go through this edge), there must not exist any edge where its dp value is greater than this edge, 
meaning for every edge whose dp value is greater, we must block that edge. This is the ONLY and fixed condition that we must
satisfy, so instead of having "blocking", we can represent the graph as a weighted graph where the weight of each edge is 
1+(# of edges whose outgoing node's dp value is greater than the current nodes dp value), and thus we've reduced this problem to SSSP.
Thus, if we can find this weight for all edge, we can just run Dijkstra, By nature of dijkstra, we are always looking at the node with 
the least dp value, and lets assume this is its final dp value. Then, since we are processing this node its the smallest value, so when 
we visit its neighbouring nodes (all nodes that are pointing to this current node), the kicker is that all previous dp values who is 
smaller than this curr dp value, that visited that node, would've already been processed. Thus, all that's left is this going to this
node, or going to another node that has not been processed, which automatically means its dp value will be greater than this node's dp). 
Thus, we can find the exact position of this node in the array as sz(aj[x])-(# of nodes that have already been processed). Thus, for
each edge we can instantly finds its weight in O(1) by storing how many of its neighbors have already been processed, then run SSSP.
To implement this, we start from node n and go to node 0 and reverse all edges.
Note for cycles or weird visit twice, since this has been simply reduced to finding SSSP on weighted graph were the weights are known, 
this doesn't matter (note for cycles specifically, the "worse" path will take dist+(size of cycle). By SSSP, we skip all worst distances.
*/


void solve() {
    int n,m;cin>>n>>m;
    vi aj[n];
    int tot[n]={0};
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        x--;y--;
        aj[y].pb(x);
        tot[x]++;
    }

    pqg<pi>pq;
    int dist[n] = {0};
    rep(i,0,n-1){
        dist[i] = INF;
    }
    pq.push({0,n-1});
    int cnt[n]={0}; // number of alr processed neighbors
    while(!pq.empty()){
        auto [d,x] = pq.top();
        pq.pop();
        if(d != dist[x]) continue;
        for(auto y : aj[x]){
            cnt[y]++; 
            if(d+1+(tot[y]-cnt[y]) < dist[y]){
                pq.push({dist[y] = d+1+(tot[y]-cnt[y]),y});
                dbg(x,y,d,tot[y],cnt[y],dist[y]);
            }
        }
    }
    dbg(dist[0],dist[1],dist[2],dist[3],dist[4]);
    cout<<dist[0]<<nl;
    
     
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}

