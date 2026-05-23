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

pair<vi,int> f(vi v, int a){

    if(a!=1e9){
        if(a==sz(v)-1 && sz(v)>1){
            int x = 1e9;
            repv(i,0,sz(v)-1){
                if(v[i] > 0){
                    x = i;
                    break;
                }
            }
            
            if(x!=1e9){
                vi temp;
                rep(i,0,x){
                    temp.pb(v[i]);
                }
                rep(i,x+1,sz(v)-1){
                    temp.pb(v[i]);
                }
                temp.pb(v[x]);
                return {temp,a-x+a-1};
            }
            else{
                return {v,-1};
            }
        }
        else{
            vi temp;
            rep(i,0,a){
                temp.pb(v[i]);
            } 
            rep(i,a+1,sz(v)){
                temp.pb(v[i]);
            }
            return {temp,a};
        }
    }
    else{
        return {v,-1};
    }
}


void solve() {
    ll n;cin>>n;
    vi v;
    while(n){
        v.pb(n%10);
        n/=10;
    }
    int ans = 1e9;
    int cnt = 0;

    // 25
    
    int curr = 1e9;
    rep(i,0,sz(v)){
        if(v[i] == 5){
            curr = i;
            break;
        }
    }
    pair<vi,int> val = f(v,curr);
    if(val.s != -1){
        vi v2 = val.f;
        int num1 = val.s;
        curr = 1e9;
        rep(i,0,sz(v2)){
            if(v2[i] == 2){
                curr = i;
                break;
            }
        }
        val = f(v2,curr);
        if(val.s != -1){
            int num2 = val.s;
            ckmin(ans, num1+num2);
        }
    }




    // 50
    
    curr = 1e9;
    rep(i,0,sz(v)){
        if(v[i] == 0){
            curr = i;
            break;
        }
    }
    val = f(v,curr);
    if(val.s != -1){
        vi v2 = val.f;
        int num1 = val.s;
        curr = 1e9;
        rep(i,0,sz(v2)){
            if(v2[i] == 5){
                curr = i;
                break;
            }
        }
        val = f(v2,curr);
        if(val.s != -1){
            int num2 = val.s;
            ckmin(ans, num1+num2);
        }
    }





    // 75
    
    curr = 1e9;
    rep(i,0,sz(v)){
        if(v[i] == 5){
            curr = i;
            break;
        }
    }
    val = f(v,curr);
    if(val.s != -1){
        vi v2 = val.f;
        int num1 = val.s;
        curr = 1e9;
        rep(i,0,sz(v2)){
            if(v2[i] == 7){
                curr = i;
                break;
            }
        }
        val = f(v2,curr);
        if(val.s != -1){
            int num2 = val.s;
            ckmin(ans, num1+num2);
        }
    }



    
    // 00
    
    curr = 1e9;
    rep(i,0,sz(v)){
        if(v[i] == 0){
            curr = i;
            break;
        }
    }
    val = f(v,curr);
    if(val.s != -1){
        vi v2 = val.f;
        int num1 = val.s;
        curr = 1e9;
        rep(i,0,sz(v2)){
            if(v2[i] == 0){
                curr = i;
                break;
            }
        }
        val = f(v2,curr);
        if(val.s != -1){
            int num2 = val.s;
            ckmin(ans, num1+num2);
        }
    }

    if(ans == 1e9){
        cout<<-1<<nl;
        return;
    }


    cout<<ans<<nl;


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

