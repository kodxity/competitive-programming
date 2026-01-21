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
    int n,k,x;
    cin>>n>>k>>x;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    sort(all(v));
    int lo = -1;
    int hi = x;
    
    while(lo < hi){
        int mid = lo + (hi-lo+1)/2;
        ll ans = 0;
        ans += max(0, v[0]-mid+1);
        ans += max(0, x-v[n-1]-mid+1);
        rep(i,0,n-1){
            ans += max(0, v[i+1]-mid - (v[i]+mid) + 1);
        } 
        if(ans >= k){
            lo = mid; 
        }
        else{
            hi = mid-1;
        }
    }
    if(lo==0){
        rep(i,0,k){
            cout<<i<<" ";
        }
        cout<<nl;
        return;
    }
    rep(i,0,v[0]-lo+1){
        if(k == 0){
            break;
        }
        cout<<i<<" ";
        k--;
    }

    repv(i,v[n-1]+lo,x+1){
        if(k==0){
            break;
        }
        cout<<i<<" ";
        k--;
    }

    rep(i,0,n-1){
        rep(j,v[i]+lo,v[i+1]-lo+1){
            if(k==0){
                break;
            }
            cout<<j<<" ";
            k--;
        }
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

