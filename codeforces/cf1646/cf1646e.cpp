#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using orderedMultiset = tree<T ,null_type,std::less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
ll MOD = 998244353;
 

/*
Let two numbers be represented as a^x and b^y. They will result to the same number
when taken to some powers ((a^x)^p_1 = (b^y)^p_2) iff a = b. Thus, every number can
be represented by the minimum integer such that the number is a power of that integer.
Let this min integer be the "base" of the number. Two integers with different bases
can never coincide.

Two such numbers coincide when they have the same base and their power products
are the same. We can precompute dp on this beforehand to see how many distinct
powers are possible for some base. Since we don't actually care about the base
themselves (diff base never coincide), we can then find every base and add the
corresponding dp value.

For calculating dp, I was originally going for a PIE solution (which is doable).
For some base b, let x be the max value such that b^x <= n. We want to find the 
number of distinct values i*j where i = 1...x and j = 1...m. We can do PIE
where we have a set of values for i, then do some combo. However, this is not
necessary. Note x <= log(1e6) = 20. Thus, we can actually brute force count this
thing since i*j is at most 20 * 1e6 = 2e7, which we can store in a 1D bool.
We go through each x, then we store the sum (number of distinct values) in array 
ans as we go along. Each time we encounter a i*j we haven't seen before, we add
1 to the ans value. Thus, we can get total number of distinct values for some
power x, and query it in O(1) since we store it in ans array. 

For each base, we get the max x it can go up to, then we visit all powers of this
base so we don't count it again, then we just add ans[x] to total sum.
*/

bool dp[20 * 1000000+1]={0};


void solve(){   
    ll n,m;cin>>n>>m;

    // precalc dp

    ll ans[21]={0};
    rep(p,1,21){
        ans[p]+=ans[p-1];
        for(int i = p;i<=p * m;i+=p){
            if(!dp[i]){
                ans[p]++;
            }
            dp[i]=1;
        }        
    }
    bool vis[n+1]={0};
    ll sum = 1; // skip i=1
    rep(i,2,n+1){
        if(!vis[i]){
            ll val = i;
            ll cnt = 0;
            while(val <= n){
                cnt++;
                vis[val]=1;
                val *= i;
            }
            sum += ans[cnt];
        }
    }
    cout<<sum<<"\n";
}


int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1; 
    // cin>>t;

    while(t--){
        solve();
    }

    return 0;
}; 