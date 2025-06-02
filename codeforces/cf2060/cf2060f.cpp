#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 998244353;


/*
Looks intiidating by n bound, but actually have the obvious hint: brute
fortce each x from 1 to k and calculate its individual answer in log time.
This is apparent since there isn't really a smart way to consider all x
as a whole. Moreover, note each number has at most log(k) divisors, so
around 17.

Originally I was thinking we say x = a1^p1 \cdot a2^p2 \cdot ... \cdot ak^pk.
Then for each power we do some stars and bars to get answer is 
\sum_{r=1}^n \prod_{i=1}^{log(x)} \binom{p_i+r-1}{r-1}. However the binomial
products make it non trivial to simpllify. 

Hint: instead, note the constraint log(k) on number of divisors. Define 
f(n,k) = an array of length n the has product of k such that each element 
must > 1. Previously we made it so some elemnts can be 0, however we have
to have a product which is bad. If we can precalculate f(n,k) where n<= log(k),
for every size m > n, it is just a matter of adding 1s. 

Let m denote size of array (including 1s). For each size n (not include 1s),
there are m-n positions avaliable to place 1s, so binom{m}{m-n} = \binom{m}{n}.
Then, we have n positions and totoal of f(n,k) ways to place n positions so
product is k. Thus for given (m,n), number of ways is \binom{m}{n}f(n,k).

Going through all pairs (m,n), total answer is
$$
\begin{align*}
\sum_{m=0}{t} \sum_{n=1}^{sz} \binom{m}{n} f(n,k) 
&= \sum_{n=1}^{sz} \sum_{m=0}{t} \binom{m}{n} f(n,k) \\
&= \sum_{n=1}^{sz} f(n,k) \cdot \sum_{m=0}{t} \binom{m}{n}  \\
&= \sum_{n=1}^{sz} f(n,k) \cdot \binom{t+1}{n+1}.
\end{align*}
$$
where t=n in original question and sz is maximum possible sz of array
containing no 1s.(sz = log(k)). Note also k here is x in the original 
sketch. This can thus be calculated in O(log(k)).

To precalculate f(n,k):
Base Case: f(1,k) = 1 since [k] is only valid array.
Inductive Step: f(n,k) = sum_{all d such that d|k} f(n-1,k/d), which just
means adding d to the end of the array. Note n is at most log(k) = 17.
Thus, we go through all 1...k at each stage and push dp its multiples
in O(klog(k), total is O(klog^2(k)).

Calculating nCk takes O(n) for precalcuation which is bad (MLE).
Instead, note in \binom{t+1}{n+1}, n<=17. Thus, we can just calculate
it at the stop since its just (t+1)*(t)*...*(t-n)/(n+1)*n*...*1, which
takes O(n) = O(log(k)) to calculate.
*/

ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}  
 
ll mult(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
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
    
    invf.assign(n + 1, 1);
    invf[n] = qexp(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i > 0; i--) invf[i] = invf[i + 1] * (i + 1) % MOD;
}
 
ll nCk(ll n,ll k) {
    if (k < 0 || k > n) return 0;
    ll top = 1;
    for (int i = n-k+1; i <= n; i++) top = mult(top, i);
    ll bottom = 1;
    for (int i = 1;i<=k;i++) bottom = mult(bottom,i);
    return mult(top,qexp(bottom, MOD-2,MOD));
}


ll f[20][100005];

void solve(){   
    
    int k,n;cin>>k>>n;
    // calculate k=1 separtely cause edge case
    cout<<n<<" ";
    rep(i,2,k+1){
        // \sum_{n=1}^{sz} f(n,k) \cdot \binom{t+1}{n+1}.
        ll ans = 0;
        rep(j,1,20){
            ans = add(ans, mult(f[j][i],nCk(n+1,j+1)));
            // cout<<j<<" "<<i<<" "<<f[j][i]<<" "<<n+1<<" "<<j+1<<" "<<nCk(n+1,j+1)<<endl;
        }
        cout<<ans<<" ";

    }   
    cout<<"\n";


}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);


    rep(i,1,20){
        rep(j,2,100005){
            if(i==1){
                f[i][j] = 1;
            }
            else{
                for(int l = 2;l*j<=100000;l++){
                    f[i][l*j] = add(f[i][l*j], f[i-1][j]); 
                }
            }
            
        }
    }

    int t=1; 
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}; 