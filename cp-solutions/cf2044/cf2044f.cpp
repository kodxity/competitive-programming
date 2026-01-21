// what's another death?
// someday ill get it :>

#include <bits/stdc++.h>
 
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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
vl v[200005];
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

gp_hash_table<long long, int, custom_hash> gooda;
gp_hash_table<long long, int, custom_hash> goodb;
void solve() {
    ll n,m,q;
    cin>>n>>m>>q;

    vl a(n);
    vl b(m);
    ll tota = 0;
    ll totb = 0;
    rep(i,0,n){
        cin>>a[i];
        tota+=a[i];
        gooda[a[i]]=1;
    }

    rep(i,0,m){
        cin>>b[i];
        totb+=b[i];
        goodb[b[i]]=1;
    }

    while(q--){
        ll x; cin>>x;
        bool good = 0;
        for(auto i : v[abs(x)]){
                ll av = i;
                ll bv = x/i;
                if(gooda[tota-av] && goodb[totb-bv]){
                    good = 1;
                    break;
                }

                    av = -i;
                    bv = -x/i;

                    if(gooda[tota-av] && goodb[totb-bv]){
                        good = 1;
                        break;
                    }
        }
        cout<<((good) ? "YES\n" : "NO\n");
    }


}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    rep(i,1,2e5+1){
            for(int j = 1;j*i<=2e5;j++){
                v[i*j].pb(i);
            }
    }
    // cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}

