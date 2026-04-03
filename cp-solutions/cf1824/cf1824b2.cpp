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

ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

ll mult(ll x, ll y){
    x %= MOD;
    y %= MOD;
    return (x*y) % MOD;
}
ll lpow(ll x, ll y)
{
    if(y <= 0){
        return 1;
    }
    ll z = 1;
    while(y)
    {
        if(y & 1) z = mult(z, x);
        x = mult(x, x);
        y >>= 1;
    }
    return z;
}

ll inv(ll x) {
    return lpow(x, MOD - 2);
}

ll divide(ll x, ll y)
{
    return mult(x, inv(y));
}

ll qexp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}
 
vector<ll> fact, invf;
 
void precompute(int n) {
    fact.assign(n + 1, 1); 
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    invf.assign(n + 1, 1);
    invf[n] = qexp(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i > 0; i--) invf[i] = invf[i + 1] * (i + 1) % MOD;
}
 
ll nCk(ll n,ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invf[k] % MOD * invf[n - k] % MOD;
}

/*
tree
what makes the node a good island?
For each k ways, you want to find the "median" node and count how many such nodes can be the median node. When we move, we
want to compare how many nodes we are adding distance by 1 (getting further) vs how many nodes we're adding by -1 (getting 
closer). The nodes we're getting further away form are all the marked nodes in the subtree of the node we're currently on,
and the number of nodes we're getting closer to is every other node. Thus, since we know this function is always monotonically
increasing, we can just say that we stop the moment we reach k/2 nodes in our current subtree.

In expected probability problems, we can try indicators where we just assume that each node is going to be a good node, then 
count in how many ways this node will be good in all arrangements, and contribute 1 to the value. So now we fix a node. 
We now want to determine when is this node good. 

Hint: If k is odd, then there exists exactly one node for every arrangement:
Proof: We prove by contradiction. Assume there exists two nodes x and y. Now WLOG we root the tree at x, then we try moving
from x to y. Suppose we move from parent to child $a$. Then, we are decreasing the distance for all people under this subtree
of $a$ by $1$, and increasing the distance for all people outside of this subtree by $-1$. Thus, let there be $s$ people
in the subtree, then we are adding $k-s -s = k-2s$ to the total distance. Since we're assuming $x$ is the node with smallest 
distance, thus $k-2s \ge 0$ because otherwise $x$ is not the node with the smallest distance. Moreover, $s$ must decrease as
we go down further since the $s$ of a parent must always be $\ge$ the $s$ of its child. Thus, we've proven that $k-2s \ge 0$ 
for all nodes onwards, so we can only increase the distance and not decrease it, and note that once we increase the distance
for the first time, then as we go further down we must keep increasing the distance. From this, we conclude that all good nodes
must be all connected. 
To prove for $k$ is odd, for $y$ to be same as $x$ the best case scenario is if $k-2s = 0 \implies k =2s$ which is false since
$k$ is odd. Thus, this is contradition. 

For $k$ is even, 
Claim: For each tree, there exists exactly 1 good node who when rooted at arbitrary node 1, its subtree is not k/2. All other good
nodes must have subtree size k/2. 
Proof: lets root the tree arbitrarily (assume at 1). If this root is a good node, we can apply above idea where we go down whenever
it's exactly k/2. Since root is good node and root does not have subtree size k/2 (instead its k), it satisfies our claim.
If root is not a good node, then the only way the total distance decreases is if a subtree has
$k-2s < 0 \implies k < 2s \implies $\frac{k}{2} < s$, so $s$ contains more than half the people, which means there exists at most
one such subtree that has that property, so we're fixed to go down that subtree. Thus, the path from this subtree to a "good" node
is fixed. When we arrive at the first instance of a good node, it is because previously we found that this subtree satisfies 
$\frac{k}{2} < s$. We then know that since this is a good node, every node below it has $\frac{k}[2} \ge s$, and this turns into
the steps we previously did for $k$ is odd. Thus, since we are bound to reach a good node with $\frac{k}{2} < s$ (eventually as
we're going down), and for all nodes below it are only good nodes if $s = \frac{k}{2}$, this also statisfies our claim.

Claim: Any node that has $s = \frac{k}{2}$ (rooted arbitrarly at 1) must be a good node.
Proof: We root at 1, then forcibly move down to the first good node where $\frac{k}{2} < s$. At this point, we know all such nodes 
must be inside this subtree. Then we've previously proven that since it's below this node (in this subtree), all such nodes must be
good node, and since $s$ is monotonically increasing, if $s < \frac{k}{2}$ it can never go back to $s = \frac{k}{2}$ again as you go
down. Thus, we've proven that all nodes satisfying $s = \frac{k}{2}$ must be under the "first good node", and all such nodes must 
also be good nodes, we've proven the claim.

Thus, we can now proceed with the solution: First we note that each arrangement must give at least 1 good node (obviously), and we
let that node be the one where its subtree is not $\frac{k}{2}$. Then, for each tree we can count the number of nodes such that
$s = \frac{k}{2}$, and that will be "additional" nodes we add to the answer. Thus for each tree, the total number of good nodes is
1 + number of nodes satisfying $s = \frac{k}{2}$ (when rooted at 1).
To count total number of good nodes, we can just fix the good node that has $s = \frac{k}{2}$, and multiply that by how many arrangements 
such that this is satified. Then, we just add the number of total possible arrangements to that sum (+1 for the non $\frac{k}{2}$ node 
for every arrangement). 
For each node, to count the number of times it satisfies $s = \frac{k}{2}$ is easy: it's just $\binom{m}{k/2} \binom{n-m}{k/2}$ where
$m$ is the number of nodes in its subtree.
*/


vi aj[200005];
int vis[200005];
int s[200005];
ll ans = 0;
int tot;
void dfs(int n, int k){
    vis[n] = true;
    s[n] = 1;
    for(auto x : aj[n]){
        if(!vis[x]){
            dfs(x,k);
            s[n] += s[x];
        }
    }
    ans = add(ans, mult(nCk(s[n],k/2),nCk(tot-s[n],k/2)));
}
void solve() {
    int n,k;
    cin>>n>>k;
    tot = n;
    ans = 0;
    rep(i,0,n){
        aj[i].clear();
        vis[i] = 0;
        s[i] = 0;
    }
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        x--;y--;
        aj[x].pb(y);
        aj[y].pb(x);
    }
    if(k%2){
        cout<<1<<nl;
        return;
    }
    ans = add(ans, nCk(n,k)); // +1 for each arrangement
    dfs(0,k);
    cout<<divide(ans, nCk(n,k))<<nl; // divide by all possible arrangements

}



int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
    precompute(200005);     
    int T = 1;
    // cin >> T;

    while(T--) {
        solve();
    }

	return 0;
}


