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
    ll n,k,s;
    cin>>n>>k>>s;
    if(s/k == 0){
        cout<<"NO\n";
        return;
    }
    if(s%k==0){
        if(s/k<n){
            ll num = 1+s/k;
            cout<<"YES\n";
            rep(i,0,k){
                cout<<num<<" ";
                num = 2+s/k - num;
            }
            cout<<nl;
        }
        else{
            cout<<"NO\n";
            return;
        }
    }
    else{
        ll m = s%k;
        if(s/k+1 < n){
            ll num = 2+s/k;
            cout<<"YES\n";
            rep(i,0,m){
                cout<<num<<" ";
                num = 3+s/k-num;
            }
            if(num == 1){
                num = 2;
                rep(i,m,k){
                    cout<<num<<" ";
                    num = 4+s/k-num;
                }
            }
            else{
                num=1+s/k;
                rep(i,m,k){
                    cout<<num<<" ";
                    num = 2+s/k-num;
                }
            }
            cout<<nl;
        }
        else{
            cout<<"NO\n";
            return;
        }
    }

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

