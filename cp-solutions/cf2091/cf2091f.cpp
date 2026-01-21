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

const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001; 
const ll INF = (1LL<<60);


/*


*/

ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}  
 
ll mult(ll x, ll y){
    x %= MOD;
    y %= MOD;
    return (x*y) % MOD;
}
ll lpow(ll x, ll y)
{
    if(y <= 0){
        return 1;
    }
    ll z = 1;
    while(y)
    {
        if(y & 1) z = mult(z, x);
        x = mult(x, x);
        y >>= 1;
    }
    return z;
}
 
ll inv(ll x) {
    return lpow(x, MOD - 2);
}
 
ll divide(ll x, ll y)
{
    return mult(x, inv(y));
}
 
ll qexp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}

void solve() {
    int n,m,d;
    cin>>n>>m>>d;

    int a[n][m];
    rep(i,0,n){
        string s;cin>>s;
        rep(j,0,m){
           a[i][j] = s[j];
        }
    }

    ll dp[n][m];
    ll pre[n][m+1];
    memset(pre,0,sizeof(pre));
    memset(dp,0,sizeof(dp));
    rep(i,0,m){
        if(a[n-1][i] == 'X'){
           dp[n-1][i] = 1;
        }
    }
    
    rep(i,0,m){
       pre[n-1][i+1] = add(pre[n-1][i], dp[n-1][i]);
    }

    rep(i,0,m){
        if(a[n-1][i] == 'X'){
           dp[n-1][i] = add(pre[n-1][min(m,i+d+1)],-pre[n-1][max(0,i-d)]);

        }
    }

    rep(i,0,m){
        pre[n-1][i+1] = pre[n-1][i] + dp[n-1][i];
    }

    repv(j,0,n-1){
        
        rep(i,0,m){
          if(a[j][i] == 'X'){
                dp[j][i] = add(pre[j+1][min(m,i+d)], -pre[j+1][max(0,i-(d-1))]); 
            }
        }
        
        rep(i,0,m){
           pre[j][i+1] = add(pre[j][i], dp[j][i]);
        }

        rep(i,0,m){
            if(a[j][i] == 'X'){
                dp[j][i] = add(pre[j][min(m,i+d+1)], -pre[j][max(0,i-d)]);

            }
        }

        
        rep(i,0,m){
           pre[j][i+1] = add(pre[j][i], dp[j][i]);
        }
    }
    
    ll ans = 0;
    rep(i,0,m){
      ans = add(ans, dp[0][i]);
    }
    
    cout<<ans<<nl;
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

