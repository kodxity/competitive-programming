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


*/
/**
 * Time: O(N\log(N))
 * Declaration: DSU dsu(n);
 * Function: 
 * - `dsu.size(x)`: returns size of component of `x`
 * - `dsu.find(x)`: returns leader of `x`
 * - `dsu.unite(x,y)`: connects `x` and `y`,
 *      - returns true if connection is successful, false if they're already connected
 */


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
        
        int size(int x){
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

void solve() {
    int n;cin>>n;
    bool bad = 0;
    int a[n][n];
    rep(i,0,n){
        string s;cin>>s;
        rep(j,0,n){
            if(i==j && s[j] == '0'){
                bad = 1;
            }
            a[i][j] = s[j]-'0';
        }
    }
    if(bad){
        cout<<"No\n";
        return;
    }
    vector<pi>ans;
    DSU dsu(n);
    rep(i,0,n){
        rep(j,0,n){
            if(i == j){
                continue;
            }
            if(a[i][j] == 1 && a[j][i] == 1){
                cout<<"No\n";
                return;
            }
            if(a[i][j]){
                int con = 1;
                rep(l,0,n){
                    if(l != i && l != j){
                        if(a[i][l] == 1 && a[l][j] == 1){
                            con = 0;
                        }
                    }
                }
                if(con){
                    if(dsu.unite(i,j)){
                        ans.pb({i,j});
                    }
                    else{
                        cout<<"No\n";
                        return;
                    }
                }
            }
            else{
                rep(l,0,n){
                    if(l != i && l != j){
                        if(a[i][l] == 1 && a[l][j] == 1){
                            cout<<"No\n";
                            return;
                        }
                    }
                }
            }
        }
    }
    if(sz(ans) != n-1){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    rep(i,0,sz(ans)){
        cout<<ans[i].f+1<<" "<<ans[i].s+1<<nl;
    }
    
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

