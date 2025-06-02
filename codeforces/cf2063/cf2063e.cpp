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
typedef tuple<int,int,int> tiii;
typedef vector<int> vi;
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
ll MOD = 998244353;
 

/*
For distances x and y, how many possible 3rd length z is valid? WLOG let y<x, 
either z is smallest, middle, or largest length. If it's smallest, we have to
make sure z+y>x, z>x-y. If it's in the middle, again z+y>x. If it's the largest,
x+y>z. Thus, x-y<z<x+y. The number of integers in this range is thus 
(x+y)-(x-y)-1 = 2y-1. 

Hint: Let d[n] = distance from node n to root 1. Then, 2y-1 = 2(d[y]-d[lca(x,y)])-1
= 2*min(d[x],d[y]) - 2*d[lca(x,y)] - 1.

It is easier to calculate these separately, then add them up. Note we do -1 
only when the pair of nodes is "valid" (when one node is not a ancestor of the
other), but we don't have to consider that for the other two calculations, thus
we calculate the 2*y for every possible pair, and -1 only for the "valid" pairs.

To calculate 2*min(d[x],d[y]), we can now exercise the normal approach of letting
every node be d[y] where d[y]<d[x], and seeing how many nodes are bigger than it. 
This is easy, since we just sort everything by distance, then the ith smallest
node will have (n-1-i) nodes whose distances is >= it. Note we account for cases
where d[y]=d[x], since we can just pick one of them (the one that comes first in
the sort), and add it only once. Thus we don't need to adjust for any overcounting.
Also note that we are counting "non-valid" pairs, but we will also count the
"non-valid" pairs for 2*d[lca(x,y)], so they just cancel to 0. 

To calculate 2*d[lca(x,y)], for each node n we let it be lca(x,y), and we 
calculate how many x,y such that n = lca(x,y) (non-valid pairs allowed). For
each n, (x,y) has n = lca(x,y) iff they are not in the same subtree of some
children of n. Thus, 
number of ways = (sz[n] choose 2) - sum_{x \in children of n}(sz[x] choose 2).
We can calculate this by keeping track of sz[n] = size of subtree of n while
doing dfs. 

To calculate -1, we must subtract 1 for each "valid" pair. While doing dfs, let
each node n be the ancestor. Then, there are exactly sz[n]-1 "invalid" pairs 
such that the ancestor is n (and the other node is a node in the subtree of n). 
There are (n choose 2) possible pairs in total, thus
number of valid pairs = (n choose 2) - sum_{n \in nodes} sz[n]-1. 
*/


vi aj[300005];
int vis[300005];
ll d[300005];
ll sz[300005];
ll ans;
void dfs(int n){
    vis[n]=true;
    ll cnt = 0;
    for(auto x : aj[n]){
        if(!vis[x]){
            d[x]=d[n]+1;
            dfs(x);
            sz[n]+=sz[x];
            cnt += sz[x]*(sz[x]-1)/2;
        }
    }
    sz[n]++;
    ans -= 2*(sz[n]*(sz[n]-1)/2-cnt)*d[n];
    ans += sz[n]-1;
    
}


void solve(){   
    ll n;cin>>n;
    ans = 0;
    rep(i,0,n){
        vis[i]=0;
        aj[i].clear();  
        d[i]=0;  
        sz[i]=0;  
    }
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        x--;y--;
        aj[x].pb(y);
        aj[y].pb(x);
    }
    d[0]=1;
    dfs(0); 
    vector<ll> v;
    rep(i,0,n){
        v.pb(d[i]);
    }
    sort(all(v));
    rep(i,0,n){
        ans += 2*(n-1-i)*v[i];
    }
    ans -= n*(n-1)/2;
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