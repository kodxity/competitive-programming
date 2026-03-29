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
a b c d
a a+b c a+b+c+d
a = a1
c = c1
b = b1 - a1
d = d1 - (a+b+c) = d1 - (a1+b1-a1+c1)
a_{-1} = a_1
b_{-1} = b_1 - 2a_1
d_{-1} = d - (b+c) = (d1-b1-c1)-(b1-a1)-(c1) = d1-2c1-2b1-a1
d_{-2} = d_{-1} - 
ar8 = ar8 - (d1 + f1 + g1)

At the nth iteration at the ith number of 2^x, coeff is just the nth row ith number of the pascal trianglei and signs
alternate each time.
To get the the next index that includes current index in its range on fenwick, add least significant bit to it.
There are at most log(N) such index so we just brute force calculate for each element each index in O(Nlog(N)).
Also, we are calculating nCk for n (k in problem statement) <= 1e9, but since each n is the same, we just calculate
once by brute force multiplying the next numerator, then divide by next denominator, at most log(N) times.
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

void solve() {
    int n,k;
    cin>>n>>k;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    int m = min(k,30);
    int nck[30] = {0};
    nck[0] = 1;
    int d = 1;
    rep(i,1,m+1){
        nck[i] = divide(mult(nck[i-1],k),d);
        dbg(i,nck[i]);
        k--; 
        d++;
    }
    int ans[n+1]={0};
    rep(i,0,n){
        int j = 0;
        int s = 1;
        int x = i+1;
        while(x<=n){
            ans[x] = add(ans[x],mult(mult(s,nck[j]),v[i]));
            int lsb = x & -x;
            x += lsb;
            s = 0-s;
            j++;
        }
    }

    rep(i,1,n+1){
        cout<<ans[i]<<" ";
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

