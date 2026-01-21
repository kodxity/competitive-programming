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
    int n; cin>>n;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }

    vector<pi>a;
    rep(i,0,n){
        int l,r;
        cin>>l>>r;
        a.pb({l,r});
    }

    int mn[n];
    int mx[n];
    rep(i,0,n){
        mn[i] = a[i].f;
        mx[i] = a[i].s;
    }

    stack <int> st;
    int cnt = 0;
    int ans[n];
    rep(i,0,n){
        if(v[i] == -1){
            if(cnt < mn[i]){
                st.push(i);
                while(cnt < mn[i] && sz(st)){
                    int x = st.top();
                    st.pop();
                    cnt++;
                    ans[x] = 1;
                }

            }
            else if(mn[i] <= cnt && cnt <= mx[i]){
                st.push(i);

                // cnt + sz(st) <= mx[i] 
                int val = mx[i] - cnt;
                val = sz(st) - val; 
                while(cnt + sz(st) > mx[i]){
                    int x = st.top();
                    st.pop();
                    val--;
                    ans[x] = 0;
                }
                if(cnt > mx[i]){
                    cout<<-1<<nl;
                    return;
                }
            }
            else{
                cout<<-1<<nl;
                return;
            }
        }
        else{
            cnt += v[i];
            ans[i] = v[i];
            
                while(cnt < mn[i] && sz(st)){
                    int x = st.top();
                    st.pop();
                    cnt++;
                    ans[x] = 1;
                }
               
                int val = mx[i] - cnt;
                val = sz(st) - val; 
                while(val>0 && sz(st)){
                    int x = st.top();
                    st.pop();
                    val--;
                    ans[x] = 0;
                }
                if(cnt){
                    cout<<-1<<nl;
                    return;
                }
           
        }


        if(cnt < mn[i] || cnt > mx[i]){
            cout<<-1<<nl;
            return;
        }
    }


    while(sz(st)){
        int x = st.top();
        ans[x] = 0;
        st.pop();
    }
    


    rep(i,0,n){
        cout<<ans[i]<<" ";
    }

    cout<<nl;


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

