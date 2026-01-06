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
still don't really get the intuition, but yes essentially we backtrack.
Let curr array be the "lower bound" of values We know from each operation no 
matter waht the lower bound of that is max(a[x],a[z]), then after, a[z] can 
be anything so we set it to 0 = lowest value. 
Also for some configuration to work, wlog a[x] = a[z] and a[y] >= a[z]. Thus
we first assume both a[x] = a[y] = a[z] (then set a[z] = 0 ofc), and in the
future if both gets turned into a[x]>a[z] then we know we're cooked. Cause
like we want to satisfy the earliest conditions first greedily, and if that
messes up the later conditions then at least we tried.
*/
 
void solve(){   
    int n,q;cin>>n>>q;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    
    }
    vector<tuple<int,int,int>>v;
    rep(i,0,q){
        int x,y,z;
        cin>>x>>y>>z;
        x--;y--;z--;
        v.pb({x,y,z});
    }

    reverse(all(v));
    vi b = a;
    rep(i,0,q){
        auto [x,y,z] = v[i];
        int temp = b[z];
        b[z] = 0;
        b[x] = max(b[x],temp);
        b[y] = max(b[y],temp);

    }

    vi c = b;

    reverse(all(v));
    rep(i,0,q){
        auto [x,y,z] = v[i];
        c[z] = min(c[x],c[y]);
    }

    if(a==c){
        rep(i,0,n){
            cout<<b[i]<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }

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