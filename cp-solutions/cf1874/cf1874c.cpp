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

vi aj[5005];
int vis[5005];
ld p[5005][5005];
void solve() {
    int n,m;
    cin>>n>>m;
    rep(i,0,n){
        vis[i] = 0;
        aj[i].clear();
    }

    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        x--;y--;
        aj[x].pb(y);
    }

    ld ans[n]={0};
    ans[n-1] = 1;
    repv(i,0,n){
        int sz = sz(aj[i]);
        vector<ld> v;
        for(auto x : aj[i]){
            v.pb(ans[x]);
        }
        sort(all(v));
        rep(j,0,sz(v)){
            ans[i] += v[j] * p[sz][j];
            dbg(i,j,sz,v[j],p[sz][j]);
        }
    }
    cout<<setprecision(10)<<ans[0]<<nl;

}



int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
    memset(p,0,sizeof(p));
    p[1][0] = 1;
    p[2][1] = 0.5;
    p[2][0] = 0;
    rep(i,3,15){
        if(i%2==1){
            rep(j,0,i){
                p[i][j] = ld(1)/ld(i);
            }
        }
        else{
            p[i][0] = 0;
            rep(j,1,i-1){
                p[i][j] = ld(1)/ld(i) * (p[i-2][j] * (i-2-j) + p[i-2][j-1] * j);
                dbg(i,j,p[i][j]);
            }
            p[i][i-1] = ld(1)/ld(i);
            
        }
    }
    
    int T = 1;
    cin >> T;

    while(T--) {
        solve();
    }

	return 0;
}

