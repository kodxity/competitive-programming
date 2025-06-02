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
dp[n] = number of ways for n nodes, each edge weight 1 to k. This looks
easy and doesn't work.

The condition for adding a new node x to the graph is:
1. The edge connecting x to 1 is smallest weight among all other 
x -> y connection weights for 2<=y<=x-1.

2. In the original graph, let weight of node y and 1 be w. Then,
weight of x -> y must be >= w. This is because otherwise, y can
just take y -> x instead of y -> 1.

Thus, whatever the edge for x -> y is dependent on the previous y
value. Thus we cannot just have a single n state.   

However, if we for each node go through 1 to k, we don't know what
each of the previous node's weight is to 1. Thus, we can't determine
its previous values (since we only have one state), so we can't solve.

The only solution to this is if the processed (added) weights is
sorted increasing, so we know current added weights (to all other
nodes except x->1) is >= weight of x -> 1, and this weight will
always be bigger than y -> 1 since its sorted.

However, if we process by sorting, then we have to deal with combo
ideas since the weights are ordered, so if we have a set of weights,
we need to consider how to distribute this weight amongst the nodes
so that the configurations are distinct. This also proves to be
difficult since we don't know distribution of each weight/how many
nodes have that weight, over all. 

Hint: We need to count this using only one k state.
Let dp[n][k] be answer with n nodes and the max weight is at most k. 
We need to fix the a specific segment length (in extra O(n)) to make
it so that we can brute force and find dp[n][k], for better calculations.
Previously I thought this still didn't solve the problem of arrangements,
but we can apply a slick trick. Previously we assumed we are fixing
the nodes as well, that dp[n] = the first n nodes 1,2,...,n. However,
we don't have to do that. We can choose the nodes as we go instead,
which will have the correct counting. For a segment length l, we
have dp[i] = n-i choose l choices for l nodes that have weight equal
to k. This provides the correct counting using only one state!
We also need to skip some weights if needed. Instead of another loop,
we can just make dp[n][k] act as a prefix sum so that instead of k
representing the max weight, it represents the max upperbound of weight.
This way we can skip by just iterating once and always adding
dp[i][j] += dp[i][j-1] for transition. Note answer is just dp[n][k].

Now we can safely calculate weights of edges excluding 1->x. Given 
some segment l and we already have i nodes in the graph, the number
of such edges (excluding 1->x l times) is i+(i+1)+...+(n+l-1) - l
= (n+l-1)*(n+l)/2 - (i-1)*i/2) - l. Note subtract l cause for each
of the l nodes we subtract edge x->1 from our count. 
Then, each of those edges has k-j+1 weights to choose from, where j
is the current upper bound weight.

*/


ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}  
    
ll mult(ll x, ll y)
{
    return (x%MOD * 1ll * y%MOD) % MOD;
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

void solve(){   
    precompute(300);
    int n,k;cin>>n>>k;
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    dp[1][0]=1;
    rep(j,1,k+1){
        rep(i,1,n+1){
            rep(l,0,n-i+1){
                dp[i+l][j]=add(dp[i+l][j], mult(mult(dp[i][j-1], nCk(n-i,l)), qexp(k-j+1,(i+l-1)*(i+l)/2 - (i) * (i-1)/2 - l,MOD)));
            }
            
        }
    }
    cout<<dp[n][k]<<"\n";
 
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