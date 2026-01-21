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
    int n,m,h;
    cin>>n>>m>>h;
    vi a(n);
    vi v(n);
    vi b(m);
    vi c(m);
    rep(i,0,n){
        cin>>a[i];
        v[i] = a[i];
    }
    int cnt = 0;
    vi aj[n];
    rep(i,0,m){
        cin>>b[i]>>c[i];
        b[i]--;
        if(sz(aj[b[i]])){
            if(aj[b[i]].back() != cnt){
                a[b[i]] = v[b[i]];
            }
        }

        a[b[i]] += c[i];
        aj[b[i]].pb(cnt);
        if(a[b[i]] > h){
            cnt++;
        }
    }
    rep(i,0,n){
       if(sz(aj[i])){
           if(aj[i].back() != cnt){
               a[i] = v[i];
           }
       }
       cout<<a[i]<<" ";
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

