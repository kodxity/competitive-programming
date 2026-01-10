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
Since we have to ask everything before getting any response, idrk how to 
make optimal moves.

Hint: fix the root, for each root do O(n).

We fix the root by going through all nodes and letting first query be
that node. Note each subtree going down is separated from the other
subtrees (outside of this subtree). That is, if we query a node inside 
the subtree, and the target node is in another subtree, then it is 
pretty much impossible to tell the actual node (since same dist), unless
its like a line or something. 
Let ans[x] = min queries needed to find a node in the subtree of x. 

If we place a node on this subtree, all nodes down such that its a line will
be automatically free. This is also a subcase unaffected by other nodes we 
asked since it isn't affected. Thus we only care about the node above at the
start of the subtree, and treat that as the root. Here, if the subtree goes 
down in a line we can disinguish it. However, it there are mutiple children we
can't distinguish it by subtree unless we query every children except at most
one of them, so dp relation off that just dp[n] + sum of dp[c] + # of children-1. 
Account for edge cases.

I mean idek fuck this problem imma go kms rn like I hate my life lololololol
wait lowkey god just wants me to keep myself safe or some shit xDDDDDDDDD I cant-


So essentially we want to at each step distinguish between subtrees of children.
This is our main goal, cause if we can distinguish a subtree from another for any
given subtree if and only if we can distinguish a node from anything else.  
Sure, one can distinguish solely by dist from root but if there exists multiple
children, we can't possible distinguish them apart from just querying the root. 
If we already queried some node inside the subtree of a child, we can distinguish 
the subtree of that child from other subtrees by distance, though we can't 
distinguish any other subtrees from each other. Thus, if we never queryed anything
within this subtree, and this subtree is a child of some node where this node has
multiple childs, we should query the root of this subtree to distinguish it from
the rest. However, we probably shouldn't do this for every child, cause if there
are m children and we can already distinguish m-1 of the children's subtrees, we
can automatically distinguish the last subtree by process of elimination. Therefore,
the answer for dp[n] is sum of dp[c] where c is child of n, + number of subtrees
that have dp[c]=0 (havent queryed anything from it, so we must query)-1.
However, if this number is 0, we don't wanna -1 so we just do max(0,cnt-1).
At the end we do dp[n]+1 cause we queryed the root. Also its 0 if and only if
we don't have to distinguish anything, which happens only when n = 1.

wow, what a fun and amazing and thoughtful problem. I totally didn't just waste
a whole fucking day doing it :))))) and I totally love life rn, like its 12am and
I just got into a some huge family drama and like life is so amazing, wow, why do
people get depression when life is so great and wonderful and wow just wow like 
honestly I love my life I have a great family, great friends, and a bright and 
totally not depressing and draining future ahead!!! It's 12am and I'm just so 
happy to be here on this planet right now like I wouldn't trade it for anything.
Honestly so grateful for everyone around me and supporting me when I'm down!
*/

int vis[2005];
vi aj[2005];
int dp[2005];
void dfs(int n){
    vis[n]=true;
    int val = 0;
    for(auto x : aj[n]){
        if(!vis[x]){
            dfs(x);
            dp[n]+=dp[x];
            if(dp[x]==0){
                val++;
            }
        }
    }
    dp[n]+=max(0,val-1);
    
}

void solve(){   
    int n;cin>>n;
    
    rep(i,0,n){
        aj[i].clear();
    }
    
    rep(i,0,n-1){
        int x,y;cin>>x>>y;
        x--;y--;
        aj[x].pb(y);
        aj[y].pb(x);
    }
    if(n==1){
        cout<<0<<"\n";
        return;
    }
    int ans = 1e9;
    rep(i,0,n){
        rep(j,0,n){
            vis[j]=0;
            dp[j]=0;
        }
        dfs(i);
        ans = min(ans,dp[i]+1);
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