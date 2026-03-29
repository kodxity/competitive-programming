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
 

/*
We prove that the cycle cannot be more than 2. Lets have ax^b, and we must add bx^a to g(x), and let g(x) have b_1x^a,
and we'll prove that b = b_1. We prove by contradiction: suppose b_1 > b, then we have $ax^{b_1}$. Then suppose we have
$a_1x^{b_1}$ where $a_1 > a$. Then we have $b_1x^{a_1}$, then we add $a_1x^{b_1}$. Suppose $a_2 > a_1$, then we have
$a_2x^{b_1}$, so we add $b_1x^{a_2}$. Suppose we have $b_2x^{a_2}$ where $b_2 > b_1$, then etc...
Suppose we arrive at some $n$ where $a_nx^{b_n}$ (or similar idea), where we add $b_nx^{a_n}$  matches with its 
coefficient in the function exactly, meaning $b_n$ is our desired coeff for exponent $a_n$. Then, we see previously
we had $b_{n-1}x^{a_n}$ added, however we assuemd that $b_n > b_{n-1}$, so we arrived at $b_{n-1}$ (or else we wouldn't 
have gotten here). However, here we are again adding $b_nx^{a_n}$, which is the actual coefficient as we assumed. Then,
this means $b_{n-1} = 0$. Then, previously we stated $b_{n-1} > b_{n-2}$, but since everything is non-negative and $b_{n-1}$,
this is a contradiction. Thus, we must go on indefinitely and never "stopping" and always assuming that $a_n > a_{n-1}$ and
$b_n > b_{n-1}$, which is always impossible since $a_n$ and $b_n$ then diverges and goes to infinity.
Doing this with a graph of length 3, we find that by this logic it is impossible to construct such a graph. However, we 
see that a graph of 2 where its like ax^b and bx^a is valid, and a graph is one is just ax^a is also valid, though by our
above proof anything with length 3 or larger is impossible.
Thus, we've proven we can only do pairs or ones. A third thing we can do (last case in example test case) is we can "eliminate"
the element with 0, where we set its value to $0$, and then since the value for 0 is always $-1$, we can set it to anything we 
want and it's dependent on the number of 0s set in our array, so we don't care what it is since its determined by the rest of
the array. Also, the thing with 0 is that after we set everything, it is then $kx^0$ to the function for some $k$, so we add
$0x^k$ which does nothing. Thus, we can treat 0 as garbage that we don't care about. Thus, for all -1 values there are 3 ways:
Pair it up with another element, set it to itself, or set it to 0. They are all independent from each other. This is true except
for the nth element, which can only be paied up or set to itself (but not set to 0 since $a_n \neq 0$ is definition). 
Thus, this problem boils down to finding the number of ways to distrbute such that every element is either paired up with another 
element, itself, or 0 (excluding nth element). 

For all values that are not -1, if its set to 0 or itself, we don't care about them. If its set to another element, then if that
element is set to our curr element then they're a pair, if its set to a different element then they are not a pair so we return 0,
and if its -1 then we are forced to set them as a pair, so only 1 choice.
Now we have all elements whose values are $-1$ and we can perform any operation freely. First we calculate for when the nth element
is paired up or alone. Then, we brute force over the number of pairs in the array and fix as $k$, then this is just the previous
value for k-1 pairs * remaining choose 2, and then the rest are either 0 or itself so we multiply by $2^{remaining}$. Then, we 
add everything up to get the final answer (note we do this for both cases of nth element and add them up).
*/


void solve() {
    int n;cin>>n;
    vi v(n+1);
    rep(i,0,n+1){
        cin>>v[i];
    }
    rep(i,1,n){
        if(v[i] == -1){

        }
        else{
            if(v[i] == i || v[i] == 0){

            }
            else{
                if(v[i] > n){
                    cout<<0<<nl;
                    return;
                }
                else if(v[v[i]] == i){

                }
                else if(v[v[i]] == -1){
                    v[v[i]] = i;
                }
                else{
                    cout<<0<<nl;
                    return;
                }
            }
        }
    }
    ll ans = 0;
    ll cnt = 0;
    rep(i,1,n){
        if(v[i] == -1){
            cnt++;
        }
    }
    dbg(cnt);
    // n is not paired up
    ll val = 1;
    ll fact = 1;
    for(ll i = cnt;i>=0;i-=2){
        ans = add(ans, mult(val, lpow(2,i)));
        val = mult(val, i*(i-1)/2);
        val = divide(val, fact);
        dbg(val,fact);
        fact++;
    }
    dbg(ans);
    // n is paired up
    if(v[n] == -1){
        val = cnt;
        cnt--;
        fact = 1;
        for(ll i = cnt;i>=0;i-=2){
            ans = add(ans, mult(val, lpow(2,i)));
            dbg(ans, i);
            val = mult(val, i*(i-1)/2);
            val = divide(val,fact);
            dbg(val,fact);
            fact++;
        }
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

