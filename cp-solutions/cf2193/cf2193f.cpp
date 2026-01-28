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


void solve() {
    ll n,ax,ay,bx,by;
    cin>>n>>ax>>ay>>bx>>by;
    set<ll>st;
    map<ll,ll>mx;
    map<ll,ll>mn;
    vl x(n);
    vl y(n);
    rep(i,0,n){
        cin>>x[i];
        st.insert(x[i]);
        mx[x[i]] = -2e9;
        mn[x[i]] = 2e9;
    }
    rep(i,0,n){
        cin>>y[i];
        ckmax(mx[x[i]],y[i]);
        ckmin(mn[x[i]],y[i]);
    }
    mx[bx] = by;
    mn[bx] = by;
    st.insert(bx); 
    ll ans = bx-ax;
    ll dp[sz(st)+1][2];
    vi v; v.pb(0);
    for(auto it = st.begin(); it != st.end();it++){
        v.pb(*it);
    }
    ll l = ay;
    ll r = ay;
    dp[0][0] = 0;
    dp[1][0] = 0;
    rep(i,1,sz(v)){
        ll x = v[i];
        dp[i][0] = min(dp[i-1][0] + abs(l-mx[x]), dp[i-1][1] + abs(r-mx[x])) + (mx[x] - mn[x]);
        dp[i][1] = min(dp[i-1][0] + abs(l-mn[x]), dp[i-1][1] + abs(r-mn[x])) + (mx[x] - mn[x]);
        l = mn[x];
        r = mx[x];
    }
    cout<<dp[sz(v)-1][0] + bx-ax<<nl;
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

