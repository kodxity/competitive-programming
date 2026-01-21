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
    char c;cin>>c;
    map<char,int>key;
    key['C'] = 0;
    key['D'] = 1;
    key['H'] = 2;
    key['S'] = 3;
    vector<string> v[4];
    rep(i,0,2*n){
        string s;
        cin>>s;
        v[key[s[1]]].pb(s);
    }
    vector<pair<string,string>>ans;
    vector<string>rem;
    rep(i,0,4){
        sort(all(v[i]));
        if(i != key[c]){

            int l = 0;
            int r = sz(v[i])-1;
            while(l < r){
                ans.pb({v[i][l],v[i][r]}); 
                l++;
                r--;
            }
            rep(j,l,r+1){
                rem.pb(v[i][j]); 
            }
        }
    }

    if(sz(v[key[c]]) >= sz(rem)){
        rep(i,0,sz(rem)){
            ans.pb({rem[i], v[key[c]][i]});
        }
        int l = sz(rem);
        int r = sz(v[key[c]])-1;
        while(l < r){
            ans.pb({v[key[c]][l], v[key[c]][r]});
            l++;
            r--;
        }
        
        rep(i,0,n){
            cout<<ans[i].f<<" "<<ans[i].s<<nl;
        }
    }
    else{
        cout<<"IMPOSSIBLE"<<nl;
    }


            

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

