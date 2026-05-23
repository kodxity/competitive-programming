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
    int n;cin>>n;
    vl v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    sort(all(v));
    vl ans[32];
    rep(j,0,32){
        pl dp[n];
        rep(i,0,n){
            dp[i] = {0,-1};
            auto it = lb(all(v), v[i] - (1LL<<j)); 
            if(*it == v[i] - (1LL<<j)){
                if(ckmax(dp[i].f, dp[(it - v.begin())].f+1)){
                    dp[i].s = (it-v.begin());
                }
            }
        }
        
        ll node = 0;
        ll mx = -1e12;
        rep(i,0,n){
            if(ckmax(mx, dp[i].f)){
                node = i;
            }
        }
        vl a;
        a.pb(v[node]);
        while(dp[node].s != -1){
            node = dp[node].s;
            a.pb(v[node]);
        }
        ans[j] = a;
    }
    
    ll node = 0;
    int mx = 0;
    
        rep(i,0,32){
            if(ckmax(mx, sz(ans[i]))){
                node = i;
            }
        }
    cout<<min(3,sz(ans[node]))<<nl;
    rep(i,0,min(3,sz(ans[node]))){
        cout<<ans[node][i]<<" ";
    }
    cout<<nl;
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

