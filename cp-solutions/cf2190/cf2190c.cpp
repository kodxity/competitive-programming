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
The lexiographically minimum array bigger p is where we switch the last possible inde such that there is a bigger index after
it, and switch it with the smallest such element who's bigger than it. Clearly we see this means the last element we're switching
must be that every element after (suffix) is strictly decreasing (but this element is smaller than the next element, but after 
that everything decreases, so we know there exists at least one element such that we can pick that to switch with this element). 
Then, the minimum is if ideally after switching, we can sort the suffix after in increasing order. That will be the greedily least
q larger than p. Coincidentally, this is best case scenario for us for taking care of rev(q) > rev(p) since sorting it in increasing
means sorting it in decreasing in rev, so its max chance that there is something bigger than the last element in the suffix gets put
to the last element, which is the first element in rev, and since we know the suffix is strictly decreasing, if there exists at least
2 elements in the suffix, we have the greedy best as the solution (since there always exists a thing that we can swap for, and after
swapping we can always find a thing that is bigger than the last element in the array, in which we can sort the suffix after and get 
the most greedy solution and also satisfies rev(q) > rev(p) automatically. 
However, this fails in some cases where the last element is the largest element in the suffix. 
More specifically, the suffix is increasing. Obviously we can't restrict ourselves to only swapping elements from the increasing suffix,
since that suffix is the "max possible" for rev already. We have to not touch this suffix with anything else. Instead, we find the last 
increasing then decreasing. To prove this, suppose the suffix is split into 3 parts: up down up, and we are trying to find the smallest
q, so we want to change a element whose index is as far back as possible. Obviously the first element we change can't be only in last 
segment (as stated above since its all up). If first element changed is in the "down" segment, then we can't swap it with an element
that's in the down segment since everything after it is smaller than it, so we try swapping it with element in "up" segment. We must swap
with something that's bigger than curr, however then we have a smaller element on the "up" segment, and a bigger element is only if we 
take for the elements after this curr element in "up" segement which messes it up even more, or elements before the curr element we're 
swapping in the "down" suffix, which contradicts our assumption that our curr element is the first element we're swapping. Thus, we've 
proven that the first element swap must occur at the "up" in the mountain, which we know can be done by mountain idea already. Now, its
left to prove that we shouldn't involve anything in the last "up" segment. However, in fact we should involve it. The idea is we will
do mountain trick for getting q > p, then for everything that remains, we sort the entire thing. Since we have up down up, this sorting
will always result in a change such that rev(q) > rev(p) (since up down up is not sorted). Also, it is the most greedy way for p > q,
so we must have the best solution here.
In general, we've proven the solution is: we find the last mountain, then swap the element just before with any min valued element after
it that's larger than it, then sort everything after this element. This is the lexiographically min result satisfying q>p and rev(q)>rev(p).



*/

int ask(int x, int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int ans;cin>>ans;
    return ans;
}
void solve() {
    int n;cin>>n;
    int inc = 1;
    int idx = -1;
    int br = -1;
    repv(i,1,n){
        if(inc == 1){
            if(ask(i,i+1) == 0){
                inc = 0;
                br = i+1;
            }
        }
        else{
            if(ask(i,i+1) == 1){
                idx = i;
                break;
            }
        }
    }
    if(idx == -1){
        cout<<"! "<<-1<<endl;
        return;
    }
    int mn = idx+1;
    rep(i,idx+1,br){
        if(ask(idx, i) == 1){
            mn = i;
        }
    }
    rep(i,br,n+1){
        if(ask(idx, i) == 1){
            if(ask(mn, i) == 0){
                mn = i;
            }
            break;
        }
    }
    int ans[n+1];
    rep(i,1,n+1){
        ans[i] = i;
    }
    ans[idx] = mn;
    ans[mn] = idx;
    vi a;
    vi b;
    rep(i,idx+1,br){
        a.pb(ans[i]);
    }
    reverse(all(a));
    rep(i,br,n+1){
        b.pb(ans[i]);
    }
    vi v;
    int i1 = 0, i2 = 0;
    while(i1 < sz(a) && i2 < sz(b)){
        if(ask(a[i1], b[i2]) == 1){
            v.pb(a[i1]);    
            i1++;
        }
        else{
            v.pb(b[i2]);
            i2++;
        }
    }
    while(i1 < sz(a)){
        v.pb(a[i1]);
        i1++;
    }
    while(i2 < sz(b)){
        v.pb(b[i2]);
        i2++;
    }
    rep(i,idx+1,n+1){
        ans[i] = v[i-(idx+1)];
    }
    

    cout<<"! ";
    rep(i,1,n+1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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

