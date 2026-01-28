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
Let x be the amount we put in, then after the first round the expected money we have
is (1000+x) * p + (1000-x) * (1-p) = 1000p + xp + 1000-x-1000p+xp
= (1000p+1000-1000p) + xp-x+xp = 1000 + x(2p-1).
This tells us that when 2p-1>=0, we should go all in every time. Else, we should put
in nothing (x = 0). 2p-1>=0 -> p >= 1/2.
Since k<=30, we can brute force this process for each p, then multiply by 1/n in the end,
then add the sums up together to get expected value of the entire thing.
Note when we are brute forcing each step, we must multiply the probability rn by p each
time, since that's the probability we are at this step rn. We do this until the probability 
goes below 50. Then we stop.

Oops, turns out this is wrong as the question assumes Jack **does not know what p is**. 
Thus, we have to make decisions without knowning if p>=1/2 or not.

Hint: Given a state of a wins and b losses, it has a chance of p^a * (1-p)^b chance of 
occuring. The expected value that this state happened for this p is thus p^a * (1-p)^b /n.
Then, the expected value that this state happened over all p is thus \sum_i p_i^a * (1-p_i)^b/n.
For some p and state a wins b losses, the probability that the next move is a win is 
p^(a+1) * (1-p)^b. Thus, the probability this happens overall is  

Okay so ya I'm lost asf. I asked ChatGPT why you can go 

But actually it's proven by manipulating Bayes Theorem and using that to model the logic.

Then the probability that you get a win from (a,b) is sum_i (p_i^{a+1}(1-p_i)^b) / sum_i p_i^a(1-p_i)^b.

*/


void solve() {
    long double n,k;
    cin>>n>>k;
    long double ans = 0;
    rep(i,0,n){
        long double p;cin>>p;
        p/=100;
        long double x = 1000;
        rep(j,0,k){
            if(p < 0.5){
                break;
            }
            x = 2*x*p;
            p *= p;
            
        }
        ans += x/n;
    }
    cout<<fixed<<setprecision(5)<<ans<<endl;

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

