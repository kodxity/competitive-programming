#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1000000007;
ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}  
 
ll mult(ll x, ll y)
{
    y %= MOD;
    x %= MOD;
    return (x * 1ll * y) % MOD;
}

/*
- When p>n, rev(n,p)=n. Thus, we only worry about k<=n. 
- Predicting we need to process each query in logn.
- n in base p = n-1,n-2,n-3,... is 11,12,13,... until n/2,
where number is 20. Process repeats until...
2 digit: n = ax + b -> bx + a
3 digit: n = ax^2 + bx + c -> cx^2 + bx + a
4 digit: n = ax

t = 5000, actually comfortably allows ~1000 per test case.
Note it will be >= 3 digits if any only if p^2 <= n.
sqrt(300000) = 548.
If we can calculate all 2 digits in 500, we can brute force 
the rest. We can fix the first digit, which is at most 
sqrt(300000) = 548, since x * (x-1)+... = n.

Example: n = 15
1 digit: > 15
2 digit: 

15,14,13,12,11,10,9,8
10,11,12,13,14,15,16,17
1,15,27,37,45,51,55,57

7,6
21,23
9,20
start with 1:

(1) + (1*(n-1)+1) + (2*(n-2)+1) + (3*(n-3)+1) + ... + (x*(n-x)+1)
until x = floor(n/2)+1. Let floor(n/2)+1 = k. Sum is 
$$
\begin{align*}
\sum_{i=0}^{k} i*(n-i)+1 = (k+1) + \sum_{i=0}^{k} in-i^2
= (k+1) + n * \sum_{i=0}^{k}i - \sum{i=0}^{k}i^2 
= (k+1) + n * k*(k+1)/2 - k*(k+1)*(2*k+1)/6
\end{align*}
$$

start with 2:
From floor(n/2) to floor(n/3)+1. Let floor(n/2) = n and
floor(n/3)+1 = k. Sum is 
$$
\begin{align*}
(2) + (2*(n-1)+2) + (4*(n-2)+2) + ...
= 2 * ((k+1) + n * k*(k+1)/2 - k*(k+1)*(2*k+1)/6).
\end{align*}
$$
Of course, we also need to add the remainders and stuff. 
remainder is just we have to add r * (n + n-1 + n-2 + ... + n-k) = r * sz * (n+n-k)/2.
Thus, start with 3 is 3 * (k+1) + n * k*(k+1)/2 - k*(k+1)*(2*k+1)/6, etc.
We can thus calculate n,k and the sum starting with some number in O(1) using math.


TLE. Maybe since bruteforce() is too slow. Maybe keep creating vectors slows it down.
We can calculate bruteforce() using 1 while loop and no vectors.
At every iteration we can get the rightmost value of n base p. We store this
to the right of our new number. Then for every iteration we shift the positions
of all values of our new number by 1 in base p. Thus afetr doing iterations, the
first appended number will be shifted to the leftmost, reversing the bits.

After debugging, apparently TLE because "z*(z+1)*(2*z+1)/6" is INSANELY slow
(why?). We can precalculate sum of squares instead of using the formula.
*/

int pre[300005]={0};
ll bruteforce(ll n, ll p){
    /*
    brute force rev(n,p)
    */
    ll ans = 0;
    while(n){
        ans = ans * p + n%p;
        n/=p;
    }
    
    return ans%MOD;
}
ll f(ll n, ll k){
    /*
    solve for some n, p = n-1,n-2,...,k
    */
    ll ans = 0;
    ll bf = sqrt(n);
    
    


    for(ll i = 1;i<=bf;i++){   
        ll x = n/i;
        ll y = max(k-1,n/(i+1));
     
        if(x <= bf || x < y) break;
        ll r = n%i;
        ll z = x-y-1;
        // ((k+1) + n * k*(k+1)/2 - k*(k+1)*(2*k+1)/6).
        ans = add(ans,i * (((z+1) + mult(x, z*(z+1)/2) - pre[z])) + mult(r, (z+1) * (x+(y+1))/2));
        // ans = add(ans,add(mult(i,((add((z+1LL), x * z*(z+1LL)/2LL) - z*(z+1)*(2LL*z+1LL)/6LL))), mult(r, sz * (x+(y+1LL))/2LL)));
        /*
        ll val = 0;
        for(int j = x;j>y;j--){
            val = add(val,bruteforce(n,j));
        
        }
        cout<<i<<" "<<x<<" "<<y<<" "<<z<<" "<<i * (((z+1) + x * z*(z+1)/2 - z*(z+1)*(2*z+1)/6)) + r * sz * (x+(y+1))/2<<" "<<val<<endl;
        */
        
    }
    return ans;




}
void solve(){   
    ll n,k;cin>>n>>k;
    ll ans = 0;
    
    ans %= MOD;
    if(k>n){
        ans = mult(n, (k-n));
        k=n;
    }
    ll bf = sqrt(n);
    rep(i,2,min(k,bf)+1){
        ans = add(ans,bruteforce(n,i));
    }
    ans = add(ans, add(f(n,2), - f(n,k+1)));
    cout<<ans<<"\n";
}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
	int t=1; 
    
    cin>>t;

    rep(i,1,300005){
        pre[i]=add(pre[i-1],mult(i,i));
    }

    while(t--){
        solve();
    }

    return 0;
}; 