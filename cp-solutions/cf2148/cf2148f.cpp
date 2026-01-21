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
    int n;cin>>n;
    pqg<pi>pq;
    vi v[n];
    int k = 0;
    rep(i,0,n){
        int m;cin>>m;
        ckmax(k,m);
        rep(j,0,m){
            int u;cin>>u;
            v[i].pb(u);
        }
        pq.push({v[i][0],i});    
    }

    int ans[k];

    rep(i,0,k){
        if(!sz(pq)){
            rep(j,0,n){
                if(i < sz(v[j])){
                    pq.push({v[j][i],j});
                }
            }
            if(!sz(pq)){
                break;
            }
        }

        int mn = pq.top().f;
        ans[i] = mn;
        pqg<pi>pq2;
        int next = 0;
        while(sz(pq)){
            if(pq.top().f == mn){
                if(i+1>=sz(v[pq.top().s])){
                    next = 1;
                }
                else{
                    pq2.push({v[pq.top().s][i+1],pq.top().s});
                }
                pq.pop();
            }
            else{
                pq.pop();
            }
        }
        if(next){
            continue;
        }
        pq = pq2;
    }

    rep(i,0,k){
        cout<<ans[i]<<" ";
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

