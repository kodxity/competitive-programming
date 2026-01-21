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

class DSU{
    private:
        vector<int>parents;
        vector<int>sizes;
    public:
        DSU(int size): parents(size), sizes(size, 1){
            for(int i = 0;i<size;i++){
                parents[i] = i;
            }
        }

        int getsz(int x){
            return sizes[find(x)];
        }


        int find(int x){
            return parents[x] == x ? x : (parents[x] = find(parents[x]));
        }

        bool unite(int x, int y){
            int xr = find(x);
            int yr = find(y);
            if(xr == yr){
                return false;
            }

            if(sizes[xr] < sizes[yr]){
                swap(xr, yr);
            }

            sizes[xr] += sizes[yr];
            parents[yr] = xr;
            return true;
        }
};

int id(char c){

    if(c == 'C'){
        return 0;
    }
    else if(c == 'O'){
        return 1;
    }
    else{
        return 2;
    }
}
void solve() {
    int n;cin>>n;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
        v[i]--;
    }

    int m; cin>>m;
    vector<pair<int, char>> a;
   
    char group[n];
    rep(i,0,n){
        group[i] = -1;
    }
    int bad[n]={0};
    int first[n];
    rep(i,0,n){
        first[i] = -1;
    }

    multiset<int>ms[n][3];
    rep(i,0,m){
        int x;
        char c;
        cin>>x>>c;
        x--;
        group[x] = c;
        ms[x][id(c)].insert(i);
        if(bad[x] == 0){
            first[x] = i;
        }
        bad[x] = 1;
        a.pb({x,c});
    }
    
    DSU dsu(n);

    rep(i,0,n){
        if(bad[i]){
            // v[i] = i;
        }
        else{
            dsu.unite(i,v[i]);
        }
    }

    
    int ans[26]={0};
    vector <tuple<int,int,int>> res; 
    rep(i,0,n){
        if(bad[i]){
            ans[group[i]-'A'] += dsu.getsz(i);
        }
    }
    repv(i,0,m){ 
        res.pb({ans['C'-'A'], ans['O'-'A'], ans['W'-'A']});
        int x = a[i].f;
        char c = a[i].s;
        

        if(first[x] == i){
            ans[c-'A'] -= dsu.getsz(x);
            int y = v[x];
            char cy;
            int mx = -1;
            auto it = ms[v[x]][0].lb(i);
            if(it != ms[v[x]][0].begin()){
                --it;
                if(mx < *it){
                    mx = *it;
                    cy = 'C';
                }
            }

            
            it = ms[v[x]]['O'-'A'].lb(i);
            if(it != ms[v[x]]['O'-'A'].begin()){
                --it;
                if(mx < *it){
                    mx = *it;
                    cy = 'O';
                }
            }

            
            it = ms[v[x]]['W'-'A'].lb(i);
            if(it != ms[v[x]]['W'-'A'].begin()){
                --it;
                if(mx < *it){
                    mx = *it;
                    cy = 'W';
                }
            }

             
            if(mx != -1){
                ans[cy-'A'] -= dsu.getsz(v[x]);
            }

            dsu.unite(x,v[x]);
            if(mx != -1){
                ans[cy-'A'] += dsu.getsz(v[x]);
            }
        }
        else{
    
            ans[c-'A'] -= dsu.getsz(x);
            char cy;
            int mx = -1;
            auto it = ms[x]['C'-'A'].lb(i);
            if(it != ms[x]['C'-'A'].begin()){
                --it;
                if(mx < *it){
                    mx = *it;
                    cy = 'C';
                }
            }

            
            it = ms[x]['O'-'A'].lb(i);
            if(it != ms[x]['O'-'A'].begin()){
                --it;
                if(mx < *it){
                    mx = *it;
                    cy = 'O';
                }
            }

            
            it = ms[x]['W'-'A'].lb(i);
            if(it != ms[x]['W'-'A'].begin()){
                --it;
                if(mx < *it){
                    mx = *it;
                    cy = 'W';
                }
            }

                ans[cy-'A'] += dsu.getsz(x);

        }

    }

    reverse(all(res));

    rep(i,0,m){
        cout<<get<0>(res[i])<<" "<<get<1>(res[i])<<" "<<get<2>(res[i])<<nl;    
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

