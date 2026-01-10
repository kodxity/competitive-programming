// what's another death?
// send the ocean my apologies

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
Hint: Define the new array to be function f([l,r]). We have f([l,r]) = [l,r] ordered. 
Since the xor functino is bijection (satisfies "if $x \oplus k = y \oplus k$, then $x = y$"
(injective) and "for any $y$, choosing $x = y \oplus$ would imply $x \oplus k = y$" (surjective),
the complement of [l,r] with respect to $\mathbb{W}$ is also a valid mapping. That is, if $f([l,r])
= [l,r]$, then $f([0,1,...,l-1] \cup [r+1,r+2,...]) = [0,1,...,l-1] \cup [r+1,r+2,...]$.
This is obvious because if every element in [l,r] can be mapped to another element in [l,r], and 
every element can only be mapped to one other element, no element outside of [l,r] can possibly
be mapped to something in [l,r] (by definition). Thus, it must be mapped into a element outside
of [l,r], hence the complement is also a valid mapping.

For [0,2^n), every number from [0,2^n) is a valid x.


We go until we reach 0 <= l < 2^{k-1} <= r < 2^k, which is possible considering we can reduce.
Then, these bounds makes it really easy to work with by restriction placed on what our x
value can be.

We can prove A \cup C is mapable iff B is mapable by restriction of x. 
Thus, we only need to find all x such that A \cup C is mappable. 

We can then prove there are two cases exactly:
Either A maps to A and C maps to C (iff kth bit is 0), or A maps to C and C maps to A (iff kth 
bit is 1).
u

For some x, if A is valid and A \cup B is valid, then B is valid. This is because for this x 
we know A is mappable to itself, and A \cup B is mappable, so only B is left (complement), thus
B is mappable to itself (since A must only map to itself and nothing else, leaving all of B left).

Else we must have A map to C entirely. 

I will now give a nice proof for how we can find this.
Conside we have a valid x such that $c \oplus x = a$. Note this is a necessary condition for x to
be valid: all $c \in C$ must be mapped onto a value $a \in A$. 
Then by restriction on $x$, since it is within the k bit range, we can represent x as
$x = (2^k-1) \oplus x'$ for some $x'$. Then, if we plug this back in we see
$a = c \oplus (2^k-1) \oplus x' = (a) \oplus x'$. This is because $c \oplus (2^k-1)$ is a element
in $A$. Thus, we can view performing xor on $x$ as performing two operations (which are necessary):
- First, do $c \oplus (2^k-1)$ on every number in $c$ so that $C \rightarrow A$ immediately
- Then, do xor for some element $x'$ so that A is mapped onto A. 
This and doing xor using $x$ is equivalent since $x = (2^K-1) \oplus x'$.
Thus, the number of valid $x$ is equivalent to the first case when A mapped to A and C mapped to C.

Thus, we can find this value as 
*/


void solve() {
    ll l,r;
    cin>>l>>r;

    if((r-l)%2==0){
        cout<<0<<nl;
        return;
    }
    ll it = -1; 
    repv(i,0,64){
       if(((1LL<<i)&l) != ((1LL<<i)&r)){
           it = i;
           break; 
       }

       l -= (l&(1LL<<i));
       r -= (r&(1LL<<i));
    
    }

    if(it == -1){
        cout<<0<<nl;
    }
    ll val = (r+1) & -(r+1); // least significant bit of r+1
    
    ll k = (1LL<<(it+1)); // most significant bit

    if(l==0){
        cout<<val-1<<nl;    
        return;
    }
    // cout<<k<<" "<<r<<" "<<l<<nl; 
    if(k-r-1 == l){
        cout<<2*min(val, l & -l)-1<<nl;
    }
    else{
        cout<<min(val, l & -l)-1<<nl;
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

