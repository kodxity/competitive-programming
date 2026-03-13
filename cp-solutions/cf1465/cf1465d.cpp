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
It will always be continuous no matter what. For example, for all ?, the optimal answer is always 000...111... or 111...000...
Anything else will worsen the answer (will increase the probabiltiy of a worse answer). If x < y, we mostly want 01. Thus, our
final configuration must be 000...111.... If x > y, we want 10, so it will be 111...000....
Thus, we can now fix the number of 0s and 1s, and our task turns into calculating the cost in O(1).
For each position ?, we calculate the cost if a 0 or a 1 is placed on it. This is simple since we just find the number of 0/1s to 
its left and 0/1s to its right. We can then create a prefix sum of this for fast querying, where pre[0/1][l..r] = the sum of cost
if all positions [l...r] is placed with 0/1. Then, we just go through each possible number of cnt[0] and calculate the total cost
in O(1). WLOG let x < y, then we prioritize 01. Then, answer is max(for(i,total?)(pre[0][1...cnt[0]] + pre[1][cnt[0]+1...total?])).
*/


void solve() {
    string s;cin>>s;
    int n = sz(s);
    ll x,y;
    cin>>x>>y;
    ll pre0[n+1]={0};
    ll pre1[n+1]={0};
    int tot = 0;
    vi v;
    rep(i,0,n){
        pre0[i+1] = pre0[i];
        pre1[i+1] = pre1[i];

        if(s[i] == '0'){
            pre0[i+1]++;
        }
        else if(s[i] == '1'){
            pre1[i+1]++;
        }
        else if(s[i] == '?'){
            tot++; 
            v.pb(i);
        }
    }
    
    ll pre[2][tot+1];
    memset(pre,0,sizeof(pre));
    ll ans = 1e18;
    ll sum = 0;
    rep(i,0,n){
        if(s[i] == '0'){
            sum += (pre1[i+1])*y + (pre1[n]-pre1[i+1])*x;
        }
        else if(s[i] == '1'){
            sum += (pre0[i+1])*x + (pre0[n]-pre0[i+1])*y;
        }
    }
    sum/=2;
    rep(i,0,sz(v)){
        pre[0][i+1] = pre[0][i] + (pre1[v[i]+1])*y + (pre1[n]-pre1[v[i]+1])*x;
        pre[1][i+1] = pre[1][i] + (pre0[v[i]+1])*x + (pre0[n]-pre0[v[i]+1])*y;
    }

    if(x<y){ // 01
        rep(i,0,sz(v)+1){
            ckmin(ans, sum + pre[0][i] + (pre[1][sz(v)]-pre[1][i]) + (i*(sz(v)-i))*x);
        }
    }
    else{ // 10
        rep(i,0,sz(v)+1){
            ckmin(ans, sum + pre[1][i] + (pre[0][sz(v)]-pre[0][i]) + (i*(sz(v)-i))*y);
        }
    }
    cout<<ans<<nl;
    
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

