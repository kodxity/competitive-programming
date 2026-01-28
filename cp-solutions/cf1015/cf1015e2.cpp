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
    int n,m;
    cin>>n>>m;
    char c[n][m];
    int a[n][m];
    memset(a,0,sizeof(a));

    rep(i,0,n){
        rep(j,0,m){
            cin>>c[i][j];
        }
    }
    vector<tuple<int,int,int>> ans;
    set<int>st1[n];
    rep(i,0,n){
        st1[i].insert(-1);
        st1[i].insert(m);
        rep(j,0,m){
            if(c[i][j] == '.'){
                st1[i].insert(j);
            }
        }
    }
    set<int>st2[m];
    rep(i,0,m){
        st2[i].insert(-1);
        st2[i].insert(n);
        rep(j,0,n){
            if(c[j][i] == '.'){
                st2[i].insert(j);
            }
        }
    }
    int pre1[n][m+1];
    memset(pre1,0,sizeof(pre1));
    int pre2[m][n+1];
    memset(pre2,0,sizeof(pre2));
    rep(i,1,n-1){
        rep(j,1,m-1){
            if(c[i][j] == '*'){
                int s = 1e9;
                auto l1 = st1[i].ub(j);
                --l1;
                ckmin(s, j-*l1);
                auto r1 = st1[i].ub(j);
                ckmin(s, *r1-j); 
                
                auto l2 = st2[j].ub(i);
                --l2;
                ckmin(s, i-*l2);
                auto r2 = st2[j].ub(i);
                ckmin(s, *r2-i);

                s--;
                if(s > 0){
                    if(j+s+2 <= m) pre1[i][j+s+2]--;
                    pre1[i][j-s+1]++;
                    if(i+s+2 <= n) pre2[j][i+s+2]--;
                    pre2[j][i-s+1]++;
                    ans.pb({i+1,j+1,s});
                }

            }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            pre1[i][j+1] += pre1[i][j];
        }
    }

    rep(j,0,m){
        rep(i,0,n){
            pre2[j][i+1] += pre2[j][i];
        }
    }

    rep(i,0,n){
        rep(j,0,m){
            a[i][j] = (pre1[i][j+1] | pre2[j][i+1]);
        }
    }

    rep(i,0,n){
        rep(j,0,m){
            if((a[i][j] > 0 && c[i][j] == '.') || (a[i][j] == 0 && c[i][j] == '*')){
                cout<<-1<<nl;
                return;
            }
        }
    }
    cout<<sz(ans)<<nl;
    rep(i,0,sz(ans)){
        cout<<get<0>(ans[i])<<" "<<get<1>(ans[i])<<" "<<get<2>(ans[i])<<nl;
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

