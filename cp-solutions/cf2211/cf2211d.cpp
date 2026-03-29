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
 
vector<ll> fact, invf;
 
void precompute(int n) {
    fact.assign(n + 1, 1); 
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    invf.assign(n + 1, 1);
    invf[n] = qexp(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i > 0; i--) invf[i] = invf[i + 1] * (i + 1) % MOD;
}
 
ll nCk(ll n,ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invf[k] % MOD * invf[n - k] % MOD;
}

/*
Hint: For the ith bit to be set as 1 (contribute to final sum) after the ANDing, it must be that all elements in the chosen 
sequence has 1 for that bit. That means coincidentally we must have all ith bit set (which is hard to do).
Let the total number of elements with ith bit set be $m$. Then, for $k$ elements to all have 1 for that bit, there are m choose k
ways to do so. Here, each of these ways yields a 1 for that bit, and you can only yield a 1 using one of these ways. Thus, we've
proven "iff" that the total sum of all contributions for this bit is exactly $\binom{m}{k}$ for given $i$ and $k$. 
Thus, we say $f(a)_k = \sum_{i=0}^{30} 2^i \cdot \binom{m(i)}{k}$ where $m(i)$ is the number of elements that have 1 on the ith bit. 
Thus, we don't care which bit is set to 1 for which element specifically, we only care about the total number of elements with 
that bit set, so we can just set the first m elements' ith bit to 1 (since we don't are which element is set to what, only sum of
count), so now we only need to find $m(i)$ for each $i$. 
Hint: To find each $m_i$, we note the case where $k = n$. We see that $f_k = f_n = \sum_{i=0}^{30} 2^i \binom{m_i}{n}$. Note that 
for this to be non-zero, $m_i \ge n \implies m_i = n$. Thus, we can find all $m_i$ such that $m_i = n$ which can be done by looking
at the number of 1 bits in our final $f_k$ value, that is, if the ith bit has 1, that means we have added $2^i \binom{n}{n}$ to our
answer, so $m_i = n$ for that bit $i$. Then we must subtract $2^i \binom{m_i}{k} = 2^i \binom{n}{k}$ for each $m_i$ for each $k$.
Since we are subtracting $\log{N}$ $m_i$s in total and each time we iterate through all $1 \le k \le n$, this is $O\log{N}$ total.
We are now left with $m_i \le n-1$. We then repeat this for $f_{n-1}$ and find its bits who are 1s, which represent the $m_i = n-1$ 
values, etc until we find all $m_i$ values possible.
*/


void solve() {
    int n;cin>>n;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    int cnt[29]={0};
    repv(i,0,n){
        rep(j,0,29){
            if((1<<j) & v[i]){
                cnt[j] = i+1;
                rep(l,0,n){
                    v[l] = add(v[l], mult(-lpow(2,j), nCk(i+1,l+1)));
                }

            }
        }
    }
    int ans[n]={0}; 
    rep(i,0,29){
        rep(j,0,cnt[i]){
            ans[j]=add(ans[j],lpow(2,i));
        }
    }
    rep(i,0,n){
        cout<<ans[i]<<" ";
    }
    cout<<nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
    precompute(100005);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}

