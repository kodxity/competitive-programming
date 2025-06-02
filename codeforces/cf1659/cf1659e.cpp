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

Since path distance queries are O(n^2logn) by online Dijkstras and
O(n^3) by offline warshall, there must be some simplification regarding
queries or limit of answer choices, to make this solvable in O(1)
query.

Note the testcases: we can see only 0,1,2 present. Can the answer
only be 0,1,2? Indeed, a closer inspection reveals that if we ever
encounter a 1 as a prefix AND, we will never be able to reach 2 as
a prefix AND later on. Similarily, if we encounter a 2 as AND, we
can never reach a 1 later on. Thus, every path must not both contain
1 and 2, meaning the choices for answer is limited to 0,1,2.

First, we see if there exists a walk such that 0 is never encountered,
as this is most optimal. This occurs when there is some walk such that
there is some bit that has 1 for every weight in that walk. We can do 
this by precomputing DSU for every bit, connecting nodes together in 
the DSU only if the designated bit of that weight is 1. Then in query,
we loop through every bit and see if the nodes are connected in that DSU.

Assume the answer is not 0. The answer is 1 if we can find and go
through a weight that ends in "10" or "00" (binary) before finding
a weight tha ends in "01", which secures 1 as a AND. Well, not 
really but ya. It's just a matter of what reaches 0 first. If we
find a path that can have x>1 -> 0, then output 1. Else if every
path must be 1 -> 0, then output 2. 

The above assumption is close, but wrong though. Again, we output 2
if and only if the last prefix AND before 0 is exactly 1. Otherwise,
we never reach 1 so we just output 1. If we can eliminate the 1 bit
through some path before reaching 0, we can output 1.

If we have x & y = some even number other than 0 (no 1 bit) where x
has a 1 bit, this must mean y is even (0 on 1st bit), and there exists
some higher bit that are both 1 in x and y. Looking at the bigger 
picture, if this occurs as a prefix walk it must mean everything 
before it has 1 on that higher bit, and in this case y is reached
where y has 0 on the 1st bit. Thus, we output 1 if and only if 
this happens, where the higher bit can be any bit > 1st. 

How to check if this happens? In our DSU we can just store an
extra value representing if there exists an even weight in this 
conncected component. If there is, and we can reach it from start,
then we know we can delete the 1, thus we output 1. If for all bits
we there never exists a even number in the connected component,
we output 2.

Also, if we can take 0 from an edge from the component, output 1.

*/

map <pii,int> weight;
int good[100001]={0}; // it connects to 0
class DSU{
    private:
        vector<int>parents;
        vector<int> sizes;
        vector<int> even;
    public:
        DSU(int size): parents(size),sizes(size,1), even(size,0){
            for(int i = 0;i<size;i++){
                parents[i]=i;
            }
        }
        int geteven(int x){
            return even[find(x)];
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
            even[xr] |= even[yr];
            if(weight[{x,y}]%2==0 || good[x] || good[y]){
                even[xr]=1;
            }
            parents[yr]=xr;
            return true;
        }
};

void solve(){   
    int n,m;cin>>n>>m;
    vector<pii>v;
    
    rep(i,0,m){
        int x,y,w;
        cin>>x>>y>>w;
        weight[{x,y}]=w;
        weight[{y,x}]=w;
        if(w%2==0){
            good[x]=1;
            good[y]=1;
        }
        v.pb({x,y});
    }

    vector<DSU> dsu(30,n+1);
    rep(i,0,30){
        for(auto x : v){
            if(weight[{x.F,x.S}] & (1<<i)){
                dsu[i].unite(x.F,x.S);
            }
        }
    }
    
    int q;cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans = 2;
        if(good[x]) ans = 1;
        rep(i,0,30){
            if(dsu[i].find(x)==dsu[i].find(y)){
                ans = 0;
                break;
            }
            if(i>0 && dsu[i].geteven(x)){
                ans = 1;
            }
        }
        cout<<ans<<"\n";
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