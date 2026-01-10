// what's another death?
// send the ocean my apologies

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

int v[MX];
int mx = 0;
int best[MX];

void f(int pos, int des, int up){
   if(pos == des){
       int val = 0;
       rep(i,0,des){
           val ^= v[i];
       }
       if(val != up){
           return;
       }
       int cnt = 0;
       rep(i,0,des){
          cnt += v[i]; 
       }
       if(ckmax(mx, cnt)){
          rep(i,0,des){
              best[i] = v[i];
          }
       }
       return;
   }

   rep(i,0,up+1){
      v[pos] = i;
      f(pos+1, des, up);
   }
}

void solve() {
    int n,k; cin>>n>>k;
    vi ans(k);
    rep(i,0,k){
        cin>>ans[i];
    }
    int mx2 = 0;
    rep(i,0,k){
        mx2+=ans[i];
    }
    f(0,k,n);
    if(mx == mx2){
        cout<<"OK"<<nl;
    }
    else{
        cout<<"WRONG "<<mx<<nl;
        rep(i,0,k){
            cout<<best[i]<<" ";
    
        }
        cout<<nl;
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

