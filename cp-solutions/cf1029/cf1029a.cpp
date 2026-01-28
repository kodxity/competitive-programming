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

template<class t> using pq = priority_queue<t>;
template<class t> using pqg = priority_queue<t, vector<t>, greater<t>>;
 
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

template<class t> bool ckmin(t& a, const t& b) { return b < a ? a = b, 1 : 0; }
template<class t> bool ckmax(t& a, const t& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1000000007;
const char nl = '\n';
const int mx = 100001; 
const ll inf = (1ll<<60);


/*


*/


void solve() {
    int n,k;
    cin>>n>>k;
    string s;cin>>s;

    int len  = n;
    rep(i,1,n){
        if(s.substr(i,n-i) == s.substr(0,n-i)){
            len = n-i;
            break;
        }
    }
    cout<<s;
    rep(i,0,k-1){
        if(n-len == 0){
            cout<<s;
        }
        else{
            cout<<s.substr(len, n-len);
        }
    }
    cout<<nl;

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

	return 0;
}

