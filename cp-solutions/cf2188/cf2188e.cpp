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
If Tom can reach a node before Jerry by jumping the larger interval, Tom wins by staying
there until Jerry arrives (which must happen since Jerry is still inside this interval by
nature of graph).
If Jerry escapes that interval, by nature of graph Tom must go into this interval (at best
he takes the edge of this interval) and arrive at where Jerry previously stood. Then Jerry wins
since whenever Tom visits a node that KJerry visited in aprevious turn, Jerry will always win as
he will always be faster.
Thus, the only way for Tom to win is either Tom is in front of Jerry in a distinct interval such that 
he can reach the end of the interval before Jerry, 
or Tom is behind Jerry but he can take a edge and arrive i front of Jerry, who is covered by this interval.

We may try fixing Tom's position, then calculating what the sum of score he will achieve if he starts at
that position. Let Tom start at position i and Jerry start at position j.
We calculate case where Tom is behind Jerry: 
For every interval in front of Tom [a,b], let x = a-i = distance between Tom and starting node. Then, Tom
will reach b before Jerry when Jerry is in [a,b] iff a <= j < b-x.
If Tom is in front of Jerry, lowkey it's just the complement of the set of vaild (i,j) for the 
previous case.

*/


void solve() {


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

