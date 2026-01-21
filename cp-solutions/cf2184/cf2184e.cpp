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

class DSU{
    private:
        vector<int>parents;
        vector<int> sizes;
    public:
	    // DSU dsu(n);
        DSU(int size): parents(size),sizes(size,1){
            for(int i = 0;i<size;i++){
                parents[i]=i;
            }
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
            parents[yr]=xr;
            return true;
        }
};


/*


*/


void solve() {
    int n;cin>>n;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }

    vpi edge[n];
    rep(i,0,n-1){
        edge[abs(v[i]-v[i+1])].pb({i,i+1});
    }

    ll ans[n+1]={0};
    DSU dsu(n); 
    repv(i,1,n){
        ans[i] = ans[i+1];
        trav(x, edge[i]){
            ll xsz = dsu.getsize(x.f);
            ll ysz = dsu.getsize(x.s);
            ans[i] -= xsz * (xsz-1) + ysz * (ysz-1);
            dsu.unite(x.f,x.s);
            ans[i] += (xsz+ysz) * (xsz+ysz-1);
        }

    }
    
    rep(i,1,n){
        cout<<ans[i]/2<<" ";
    }

    cout<<nl;
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

