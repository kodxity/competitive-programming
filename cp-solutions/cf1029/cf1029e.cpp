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


/*


*/

int good[200005]={0};
vi aj[200005];
int vis[200005]={0};
int ans[200005]={0};
int dfs(int n){
    vis[n] = 1;
    int mx = 0;;
    trav(x, aj[n]){
        if(!vis[x]){
            ckmax(mx, dfs(x));
        }
    }
    if(sz(aj[n]) == 1){
        return 2;
    }
    if(mx == 2){
        ans[n] = 1;
        return 0;
    }
    else{
        return mx+1; 
    }
}

void solve() {
    int n;cin>>n;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        x--;y--;
        aj[x].pb(y);
        aj[y].pb(x);
    }
    vis[0]=1;
    trav(x, aj[0]){
        good[x] = 1;
        dfs(x);
        ans[x] = 0;
    }
    int sum = 0;
    rep(i,0,n){
        sum += ans[i];
    }
    cout<<sum<<nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}

