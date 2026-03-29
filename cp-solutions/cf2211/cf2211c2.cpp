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

// DEBUG
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


/*


*/


void solve() {
    int n,k;
    cin>>n>>k;
    vi a(n);
    vi b(n);

    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        cin>>b[i];
    }
    
    rep(i,0,k){
        set<int>st;
        int idx = 0;
        bool eq = 1;
        for(int j = i;j<n;j+=k){
            if(b[j] != -1){
                if(a[j] != b[j]){
                    eq = 0;
                }
                idx = j;
                st.insert(b[j]);
            }
        }
        set<int>st2;
        for(int j = i;j<n;j+=k){
            st2.insert(a[i]);
        }
        if(sz(st)>1){
            if(eq){
                for(int j = i;j<n;j+=k){
                    b[j] = a[j];
                }
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
        else if(sz(st) == 1){
            if(eq){
                for(int j = i;j<n;j+=k){
                    b[j] = a[j];
                }
            }
            else{
                if(sz(st2)==1){
                    for(int j = i;j<n;j+=k){
                        b[j] = b[idx];
                    }
                }
                else{
                    cout<<"NO\n";
                    return;
                }
            }

        }
        else{
            if(sz(st2) > 1){
                for(int j = i;j<n;j+=k){
                    b[j] = a[j];
                }
            }
        }
    }
    int cnt[n+1]={0};
    rep(i,0,k){
        if(b[i] != -1) cnt[b[i]]++;
    }
    int cnt2[n+1]={0};
    rep(i,0,k){
        cnt2[a[i]]++;
    }
    queue<int>q;
    rep(i,0,k){
        if(b[i] == -1) q.push(i);
    }
    rep(i,0,k){
        if(cnt[a[i]] > cnt2[a[i]]){
            cout<<"NO\n";
            return;
        }
        else if(cnt[a[i]] < cnt2[a[i]]){
            cnt[a[i]]++;
            if(q.empty()){
                cout<<"NO\n";
                return;
            }
            b[q.front()] = a[i];
            q.pop();
        }
    }
    rep(i,0,k){
        if(cnt[a[i]] != cnt2[a[i]] || b[i] == -1){
            cout<<"NO\n";
            return;
        }
    }
    rep(i,k,n){
        if(a[i-k] == b[i-k]){
            cnt[a[i-k]]--;
            cnt2[b[i-k]]--;
            if(a[i] != b[i] && b[i] != -1){
                cout<<"NO\n";
                return;
            }
            b[i] = a[i];
            cnt[a[i]]++;
            cnt[b[i]]++;
        }
        else{
            if(a[i] != a[i-k]){
                cout<<"NO\n";
                return;
            }
            if(b[i] != b[i-k] && b[i] != -1){
                cout<<"NO\n";
                return;
            }
            b[i] = b[i-k];
        }
    }
    cout<<"YES\n";
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


