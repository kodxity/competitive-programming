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
Hint: Let f(i) = k, where k is the minimum such that adding the first k edges
will connect node i to i+1 through some path. Then, having all l<=a<b<=r
will connect to each other iff l is connected to l+1, l+1 to l+2,...,r-1 to r.
To prove this, assume all l<=a<b<=r is connected to each other, then its 
obvious that this condition is satisfied, since this is just letting b = a+1.
To prove inverse, wlog a < b, then a is connected to a+1, which is connected
to a+2,..., b-1 is connected to b. Thus, these two conditions are equivalent
to each other. 
This means the answer for query l,r is just max(f(l),f(l+1),...,f(r-1)). If
we can calculate each f(i), we can just get the answer for each query using 
a max segtree.
To calculate all f(i) quickly, we can process the edges in order, then for 
each edge, we'll check which i it satisfied, that previously was not satisfied
(i was previously not connected to i+1, but now is connected with the addition
of this edge).
To check this, we use a DSU and unite the edges while going through them. Each
time we unite two cc's, only the united nodes will be affected. Thus we focus
on the smaller sized cc. By small to large merging idea, if we always process
the smaller size, each node will at most be processed log(n) times. For each
node, it will only possibly affect the node before, or after it. That is, for
node x it will only possibly be change f(x-1) or f(x) after the unite. We can
then check if x-1 and x+1 are in the opposing cc we are uniting with. If they
are, then this edge will be the first time they are united, so f[x-1] or f[x] 
will equal this current index. Processing each node takes log(n) time lookup
(to find leader), each node is processed log(n) times, and there are n nodes.
Thus, we can find all f(i) in O(nlog^2(n)). We then store the f(i) in max
segtree and get query answer in log(n).
*/



int f[100005];

class DSU{
    private:
        vector<int>parents;
        vector<int> sizes;
        vector<vi>v;
    public:
	    // DSU dsu(n);
        DSU(int size): parents(size),sizes(size,1),v(size){
            for(int i = 0;i<size;i++){
                parents[i]=i;
                v[i].pb(i);
            }
        }

        int getsize(int x){
            return sizes[find(x)];
        }

        int find(int x){
            return parents[x] == x ? x : (parents[x] = find(parents[x])); 
        }

        bool unite(int x, int y, int k){
            int xr = find(x);
            int yr = find(y);
            if (xr == yr){
                return false;
            }

            if(sizes[xr] < sizes[yr]){
                swap(xr,yr);
            }
            for(auto n : v[yr]){
                v[xr].pb(n);
                if(n>0 && find(n-1)==xr){
                    f[n-1]=k;
                }
                if(n+1<sz(parents) && find(n+1)==xr){
                    f[n]=k;
                }
            }
            sizes[xr] += sizes[yr];
            parents[yr]=xr;
            return true;
        }
};

struct item{
    ll num;
};
 
struct segtree{
    int sz;
    vector <item> val; // store sum of nodes    
    item neutral = {0}; // EMPTY SEGMENT: we can add this element 
    // to anything and get the original result 
    item merge(item a, item b){ // merge two nodes( their items)
        return {max(a.num,b.num)}; // use formula to merge two items   
    }
    item single(ll v){ // we are left with single node( base case)
        return {v}; 
    }

    void init(int n){ // create empty segtree with length at least n increased to closest power of 2(for leaves of binary tree)
        sz = 1;
        while(sz < n){
            sz *= 2;
        }
        val.assign(2*sz,neutral); // create empty segtree size 2*sz and fill with 0s
    }
    void set(int i, ll u){
        set(i,u,0,0,sz);
    }
    void set(int i, ll u, int x, int lx, int rx){
        if(rx-lx==1){ // current node is a leaf
            val[x] = single(u);
            return;
        }
        int m = (lx+rx)/2; // mid
        if(i < m){ // left subtree
            set(i, u, 2*x+1,lx,m);
        }
        else{ // right subtree
            set(i, u, 2*x+2,m,rx);
        }
        val[x] = merge(val[2*x+1], val[2*x+2]);
    }
    item query(int l, int r){
        return query(l,r,0,0,sz);
    }
    item query(int l, int r, int x, int lx, int rx){
        if(r <= lx || rx <= l){ // outside range
            return neutral;
        }
        if(l <= lx && rx <= r){ // inside range
            return val[x];
        }
        int m = (lx+rx)/2;
        item osa = query(l,r,2*x+1,lx,m);
        item nosa = query(l,r,2*x+2,m,rx);
        return merge(osa, nosa);
    }
 
};

void solve(){   
    int n,m,q; 
    cin>>n>>m>>q;
    vector<pii>v;
    DSU dsu(n);
    rep(i,0,n){
        f[i]=0;
    }
    rep(i,0,m){
        int x,y;cin>>x>>y;
        x--;y--;
        v.pb({x,y});
        dsu.unite(x,y,i+1);
    }
    
    segtree st;
    st.init(n);

    rep(i,0,n){
        st.set(i,f[i]);
    }

    while(q--){
        int l,r;cin>>l>>r;
        l--;r--;
        // edge case
        if(l==r){
            cout<<0<<" ";
            continue;
        }

        cout<<st.query(l,r).num<<" ";
        
    }
    cout<<"\n";
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