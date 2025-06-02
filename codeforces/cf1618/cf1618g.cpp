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
For some fixed k, note that we can go from a to b iff there is a series of 
connections between a and b that we can jump such that the gaps between each
jump is <= k. This is an obvious sequence that leads to DSU ideas. Assume at k
we merged a in a component where a can reach any other node via a series of
jumps with gaps <= k. Then, we can just put a into pile 2, then take b (largest)
value a can reach and add it to our answer. 

We can process the merges by calculating queries offline and sorting them by value,
since if we process x before y where x <= y, y is automatically satisfied already for
all k below y, so we only have to merge the nodes whose value is exactly y. Thus,
we sort queries by ascending, and sort gaps of nodes by ascending. Then, whenever
we process a new query, we merge all gaps whose weight is between q[i-1] and q[i]
where q[i] is current query value and q[i-1] is previous, since it's sorted by
ascending order we can just add the connections as we go, which saves time.

Now we have for a fixed k, the connected components of all nodes. We can prove
that for some connected component, given that we originally had x numbers in pile
1 in that component, then we can just take the largest x values in this component
as our final answer. First, note this is obviously the best case scenario (since
nodes in this connected component can only interact/switch with other nodes in the
same connected component). Then, we must prove this is always achievable. Consider
this strategy: at a given point, find the current max value in this cc, and the 
smallest value in this cc that was originally in pile 1. We know it is always 
possible to switch these two nodes (put smallest val into pile 2, and put max val
into pile 1) through some trades since they are in same cc. Then, we can safetly
pretend to "erase" these two values, taking the max value into out answer, and now
we once again have the same subproblem, but the max value is the 2nd max. We can
repeat this process until we've taken all x largest values.

A small problem then arises (what stumped me for a while), is that we must find 
both x and the sum of x largest values for every cc, and update answers fast. 
Finding x is easy. Maintain a array "num" denoting the number of values originally
in pile 1 (x), then during merging we just add num[xr] and num[yr] together. The
other problem stumped me for some time. I was thinking of maintaining arrays that
store sorted values for each cc, then using 2 pointers or something to construct
the x largest values. However, this would probably TLE or MLE. But the solution 
is embarassingly easy after some thought. Note the obvious that whenever we merge 
two nodes, they are always right next to each other in the sorted number line 
(no values in between). Then, note if we are combining these two cc's, then the 
largest x numbers can just be calculated as pre[mx] - pre[mx-x] where pre is the
prefix sum of the values we can precompute, and mx is the index of the largest 
value in the cc (the index of the rightmost element), which works since in the
number line, the values are sorted from right to left by max to min already, so
we don't hvae to do anything!
*/


ll pre[400005]={0};
ll currans = 0;

class DSU{
    private:
        vector<int>parents;
        vector<int> sizes;
        vi num;
        vi mx;
        vector<ll> sum;
        
    public:
        DSU(int size): parents(size),sizes(size,1),num(size,0),mx(size),sum(size){
            for(int i = 0;i<size;i++){
                parents[i]=i;
                mx[i]=i;
            }
        }
        void setnum(int x, int val){
            num[x]=1;
            sum[x]=val;
        }
        int getsize(int x){
            return sizes[find(x)];
        }

        int find(int x){
            return parents[x] == x ? x : (parents[x] = find(parents[x])); 
        }

        bool unite(int x, int y){
            int xr = find(x);
            int yr = find(y);
            if (xr == yr){
                return false;
            }

            if(sizes[xr] < sizes[yr]){
                swap(xr,yr);
            }
            sizes[xr] += sizes[yr];
            num[xr] += num[yr];
            mx[xr] = max(mx[xr],mx[yr]);
            currans -= sum[xr];
            currans -= sum[yr];
            sum[xr] = pre[mx[xr]+1] - pre[mx[xr]-num[xr]+1];
            currans += sum[xr];
            parents[yr]=xr;
            return true;
        }
};

map<int,vi>mp;
map<int,int>val;
void solve(){   
    int n,m,q;
    cin>>n>>m>>q;

    set<int>st;
    vector<pii> v;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
        st.insert(a[i]);
        v.pb({a[i],0});
        currans += a[i];
    }

    vi b(m);
    rep(i,0,m){
        cin>>b[i];
        st.insert(b[i]);
        v.pb({b[i],1});
    }
    sort(all(v));
    DSU dsu(n+m);
    int idx = 0;
    for(auto it = st.begin();it != st.end(); it++){
        val[*it]=idx;
        idx++;
    }
    rep(i,0,sz(v)){
        if(v[i].S==0) dsu.setnum(i,v[i].F);
        pre[i+1] = pre[i] + v[i].F;
    }

    rep(i,0,sz(v)-1){
        mp[v[i+1].F-v[i].F].pb(i);
        
    }
    vector<pii>qy;

    rep(i,0,q){
        int u;cin>>u;
        qy.pb({u,i});
    }

    ll ans[q];
    sort(all(qy));
    auto it = mp.begin();  
    rep(tc,0,q){
        auto [x,j] = qy[tc];
        while(it != mp.end() && (it->first) <= x){
            vi arr = (it->second);
            rep(i,0,sz(arr)){
                dsu.unite(arr[i],arr[i]+1);
            }
            it++;

        }
        ans[j] = currans;
    }
    

    rep(i,0,q){
        cout<<ans[i]<<"\n";
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