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
Assume we currently have two numbers we are considering x and x+1. Then, look
at the split after. If x be even, then x is split into x/2 and x/2, and 
x+1 is split into x/2 and x/2+1. Similarly if x is odd, then x is split into (x-1)/2
and (x+1)/2 and x+1 is split into (x+1)/2 and (x+1)/2. We can see given two possible
numbers on the ith move, there are at most 2 possible numbers we can obtain on the i+1th
move.

We start with one number n. If n is even it splits into n/2 and n/2. If n is odd, then
it's split into n/2 and n/2+1. 

Since for base case we have at most two numbers, and each transition result gives us at 
most two numbers, we can see that for each step there are at most two numbers. Thus, we 
can just keep track of them and compare to k each time.

*/


void solve() {
    ll n,k;
    cin>>n>>k;
    if(n==k){
        cout<<0<<nl;
        return;
    }
    else if(n < k){
        cout<<-1<<nl;
        return;
    }
    int a = n/2;
    int b = (n+1)/2;
    int ans = 1;
    
    while(a != 0){
        if(a == k || b == k){
            cout<<ans<<nl;
            return;
        }
        a = a/2; // min possible value
        b = b/2 + b%2; // max possible value
        ans++;
    }

    cout<<-1<<nl;


     

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

