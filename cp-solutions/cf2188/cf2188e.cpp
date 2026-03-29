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
const ll INF = (1LL<<60);

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
If Tom can reach a node before Jerry by jumping the larger interval, Tom wins by staying
there until Jerry arrives (which must happen since Jerry is still inside this interval by
nature of graph).
If Jerry escapes that interval, by nature of graph Tom must go into this interval (at best
he takes the edge of this interval) and arrive at where Jerry previously stood. Then Jerry wins
since whenever Tom visits a node that KJerry visited in aprevious turn, Jerry will always win as
he will always be faster.
Thus, the only way for Tom to win is either Tom is in front of Jerry in a distinct interval such that 
he can reach the end of the interval before Jerry, 
or Tom is behind Jerry but he can take a edge and arrive i front of Jerry, who is covered by this interval.

We may try fixing Tom's position, then calculating what the sum of score he will achieve if he starts at
that position. Let Tom start at position i and Jerry start at position j.
We calculate case where Tom is behind Jerry: 
For every interval in front of Tom [a,b], let x = a-i = distance between Tom and starting node. Then, Tom
will reach b before Jerry when Jerry is in [a,b] iff a <= j < b-x.
If Tom is in front of Jerry, lowkey it's just the complement of the set of vaild (i,j) for the 
previous case.

Day 2: I looked at editorial after thinking abt it more. I think I was stuck on positions and didn't realize
the whole thing is just a tree.

Lemma 1: It is most optimal at each node to go as far as possible
Thus, we always keep edge that goes the furthest, so the graph is just a tree.

Lemma 2: After we have the connected tree, the two nodes meet at lca(x,y), so whichever gets there first wins,
and we let that be Tom. WLOG let x distance be closer, then, f(x,y) = distance from the closer node to the 
lca = d[x] - d[lca(x,y)] where d[n] is depth of node n (distance from root (=n) to curr node n)

We want to calculate sum d[x] - d[lca(x,y)]. This seems hard but we separate them individually.

We can calculate sum of all d[x] and sum of all d[lca(x,y)]. 
The sum of all d[x] is just we sort all d[x] in asc, and then number of times this d[x] contributes to sum
is the number of time this d[x] is the smaller one, so its just n-i, and if two elements are equal this 
takes care of it since we're "pretending" one is bigger than the other.

To calculate sum of d[lca(x,y)], we fix each node as lca(x,y), then its just the size of the subtree choose 2
- sum of all subtree sizes their size choose 2. Note their subtree size denote size including its root, since
we can also pick root and something in the subtree asw, so root is included.

However, if the two distances to lca are equal, then both nodes are valid. Thus, for each pair of nodes (x,y) 
such that d[x] = d[y], we have to add another d[x] - d[lca(x,y)]. To calculate this, we use DSU on Tree 
https://codeforces.com/blog/entry/44351. 
*/

int vis[200005];
ll sz[200005];
vi aj[200005];
ll d[200005];
ll ans = 0;
void dfs(int n){
    vis[n] = true;
    trav(x, aj[n]){
        if(!vis[x]){
            d[x] = d[n] + 1;
            dfs(x);
            sz[n] += sz[x];
            ans += 1LL * d[n] * (sz[x] * (sz[x]-1))/2;
        }
    }
    sz[n]++;
    ans -= 1LL * d[n] * (sz[n] * (sz[n]-1))/2;
}

map<ll, ll> *cnt[200005];
void dfs2(int v, int p){
    int mx = -1, bigChild = -1;
    for(auto u : aj[v])
       if(u != p){
           dfs2(u, v);
           if(sz[u] > mx)
               mx = sz[u], bigChild = u;
       }
    if(bigChild != -1)
        cnt[v] = cnt[bigChild];
    else
        cnt[v] = new map<ll, ll> ();
    (*cnt[v])[ d[v] ] ++;
    for(auto u : aj[v])
       if(u != p && u != bigChild){
           for(auto x : *cnt[u]){
               ans += 1LL * (x.first - d[v]) * (*cnt[v])[x.first] * x.second;
               (*cnt[v])[x.first] += x.second;

           }
                
       }
    //now (*cnt[v])[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.

}

void solve() {
    int n,m;
    cin>>n>>m;
    ans = 0;
    rep(i,0,n){
        vis[i] = 0;
        sz[i] = 0;
        d[i] = 0;
        aj[i].clear();
    }

    int best[n] = {0};
    rep(i,0,n-1){
        best[i] = i+1;
    }
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        x--; y--;
        ckmax(best[x], y);
    }
    rep(i,0,n-1){
        aj[best[i]].pb(i);
    }
    dfs(n-1);
    dbg(ans);
    vector<ll> v;
    rep(i,0,n){
        v.pb(d[i]);
    }
    sort(all(v));
    rep(i,0,n){
        ans += 1LL * v[i] * (n-i-1);
    }
    dfs2(n-1,-1); 


    cout<<ans<<nl;


}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}

