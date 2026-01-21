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



ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}  
 
ll mult(ll x, ll y){
    x %= MOD;
    y %= MOD;
    return (x*y) % MOD;
}
ll lpow(ll x, ll y)
{
    if(y <= 0){
        return 1;
    }
    ll z = 1;
    while(y)
    {
        if(y & 1) z = mult(z, x);
        x = mult(x, x);
        y >>= 1;
    }
    return z;
}
 
ll inv(ll x) {
    return lpow(x, MOD - 2);
}
 
ll divide(ll x, ll y)
{
    return mult(x, inv(y));
}
 
ll qexp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}
 
vector<ll> fact, invf;
 
void precompute(int n) {
    fact.assign(n + 1, 1); 
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    invf.assign(n + 1, 1);
    invf[n] = qexp(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i > 0; i--) invf[i] = invf[i + 1] * (i + 1) % MOD;
}
 
ll nCk(ll n,ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invf[k] % MOD * invf[n - k] % MOD;
}


struct segtree{
    int sz;
    vector <ll> val; // store multiply of each node
    vector <ll> mn; // store sum of nodes
    long long no = 0; // node does not have operation
    // CODE FOR IMPL
    
    void init(int n){ // create empty segtree with length at least n increased to closest power of 2(for leaves of binary tree)
        sz = 1;
        while(sz < n){
            sz *= 2;
        }
        val.assign(2*sz,1); // create empty segtree size 2*sz and fill with 0s
        rep(i,0,2*sz) mn.pb(0); // filled with 0s at the start
    }
    void build(){
        build(0,0,sz);
    }
    void build(int x, int lx, int rx){ // build segtree with everything 1 at the start
        if(rx-lx==1){
            mn[x]=1LL;
            return;
        }

        int m = (lx+rx)/2;
        build(2*x+1,lx,m);
        build(2*x+2,m,rx);
        mn[x]=mult(add(mn[2*x+1],mn[2*x+2]),val[x]);
        //mn[x]=1;
    }
    void display(){
        rep(i,0,2*sz){
            cout<<mn[i]<<" ";
        }
        cout<<endl;
    }
    void modify(int l, int r, int v){
        modify(l,r,v,0,0,sz);
    }
    void modify(int l, int r, int v, int x, int lx, int rx){ // modify segement [l...r)
        // l and r = desired range, x = current node, lx and rx = current range
        if(r <= lx || rx <= l){ // curr range is outside of desired range entirely
            return;
        }
        if(l <= lx && rx <= r){ // curr range is inside of desired range entirely
            //perform operation
            val[x]=mult(val[x],v);
            mn[x]=mult(mn[x],v);
            return; // break
        }
        // else dfs through left and right node
        int m = (lx+rx)/2; 
        modify(l,r,v,2*x+1,lx,m);
        modify(l,r,v,2*x+2,m,rx);
        mn[x]=mult(add(mn[2*x+1],mn[2*x+2]),val[x]);
    }
        
    ll get(int l, int r){
        return get(l,r,0,0,sz);
    }

    ll get(int l, int r, int x, int lx, int rx){ // assign ith element to u and update sums above it
        // i = desired final position(leaf), u = value we want to assign, x = current node, lx, rx = current range of node
        if(r <= lx || rx <= l){ // curr range is outside of desired range entirely
            return no; 
        }
        if(l <= lx && rx <= r){ // curr range is inside of desired range entirely
            return mn[x];
        }
        int m = (lx+rx)/2; // mid
        return mult(add(get(l,r, 2*x+1,lx,m),get(l,r, 2*x+2,m,rx)),val[x]); // find sum, then multiply
    }
};
 

 

/*


*/


void solve() {
    int n,d;
    cin>>n>>d;
    
    vector<pi>v;

    vi a;
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        v.pb({x,y});

        if(y == 1){
            a.pb(x);
        }
    }

    segtree st;
    st.init(sz(a));
    st.build();
    rep(i,0,n){
        if(v[i].s == 0){
            int x = v[i].f;
            auto it = lb(all(a),x-d);
            auto itr = lb(all(a),x);
            if(it != a.end()){
                cout<<x<<" "<<i<<nl;
                if(*it <= x){
                    int l = (it - a.begin());
                    int r = (itr - a.begin());
                    st.modify(l,r,2);
                }

            }
        }
        else{
            /*
            rep(j,0,i){
                if(v[j].s == 1){
                    auto it = lb(all(a), v[j].f);
                    cnt += st.get((it - a.begin()));
                    cout<<i<<" "<<j<<" "<<cnt<<endl; 
                }
            }
            */
            auto it = lb(all(a), v[i].f);
            ll cnt = add(st.get(0,(it-a.begin())),1LL);
            st.modify((it-a.begin()), (it-a.begin())+1,cnt);
        }
    }
    ll ans = 0;
    cout<<st.get(0,sz(a))<<nl; 
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

