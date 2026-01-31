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
    int x,y;
    cin>>x>>y;
    int val = (x & y);
    int a = (x^val);
    int b = (y^val);
    int it = 0;
    for(int i = 0;i<31;i++){
        if((1<<i) > val){
            it = i;
            break;
        }
    }
    
    int a1 = (x^val)+val;
    int b1 = (y^val)+((~(x|y)) & ((1<<it)-1));
    int ans = abs(x-a1) + abs(y-b1);
    repv(i,it,31){
        if(!((x|y) & (1<<i))){
            if(ckmin(ans, abs(x-(a-(a&((1<<i)-1))+(1<<i))))){
                a1 = (a-(a&((1<<i)-1))+(1<<i));
                b1 = y;
            }
            if(ckmin(ans, abs(y-(b-(b&((1<<i)-1))+(1<<i))))){
                a1 = x;
                b1 = (b-(b&((1<<i)-1))+(1<<i));
            }
        }
    }
    cout<<a1<<" "<<b1<<nl;
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

