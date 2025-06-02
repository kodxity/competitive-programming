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
typedef tuple<int,int,int> tiii;
typedef vector<int> vi;
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
ll MOD = 998244353;
 

/*
A classical idea is as follows (I seen it before appearing in a bunch of blue
problems, I remember specifically writing the formal proof to this when solving
some 1900 or smth problem a while ago, but I forgot the actual proof :(, 
hopefully someday I'll write this idea formally in my notes): Given a list
of numbers, we are asked to find the maximum pairs we can pair up such that
a the numbers of each pair cannot be the same. The answer to this is as follows:
Let the maximum occuring element appears k times. If k <= n/2, then everything 
can be paired up (n/2 pairs). Else, only n-k pairs can be formed (we remove this
element until it appears half of total, then everything can be removed). Again 
I forgot how to prove this but this is a classic problem that has been proved. 

Hint: let dp[i] = max answer ending at i.

From this, we thus know the condition in which we can erase some segment from
the array entirely. Thus we can calculate dp[i] = the answer where the last 
included element is i, and the previous element included in final answer is j
for some j. This is the template which incoporates all possible answer, since 
the last element before adding i must come from some j, such that j<i. Note that
we must have a[i]=a[j]. Then, it must be that a[j+1...i-1] is completely
erasable. These are the only conditions in which we can append i after j. Thus
dp[i] = dp[j]+1. 

To account for a[i]=a[j] is easy. For the second condition, we refer to our
idea above. We can eliminate some array iff array size is even (we can pair
them up evenly), and mx <= sz/2, where mx is the count of most occuring 
element, and sz is size of whole array. We can calculate this in O(n) by
simulating the proess. We go back from j = i-1 to j = 0, each time we update
sz by adding 1, and mx by maintaining a map counting number of occurances of
each element. In the end, we can take dp[i] as an answer iff we can eliminate
all a[i+1...n]. Thus we run this idea again and check if we can eliminate it.
Note we make the dp 1-indexed to account for dp[0] = empty set = 0, then set
every other dp to -inf. Map TLE, but we can use array instead since a[i]<=n.
*/


void solve(){   
    int n;cin>>n;
    vi v(n+1);v.pb(0);
    int dp[n+1];
    rep(i,1,n+1){
        cin>>v[i];
        dp[i]=-1e9;
    }
    dp[0]=0;
    rep(i,1,n+1){
        int mp[n+1]={0};
        int mx = 0;
        int sz = 0;
        for(int j = i-1;j>=0;j--){
            if((v[j]==v[i]||j==0) && sz%2==0 && mx<=sz/2){
                dp[i]=max(dp[i],dp[j]+1);
            }
            mp[v[j]]++;
            mx=max(mx,mp[v[j]]);
            sz++;
        }
    }
    int mp[n+1]={0};
    int mx = 0;
    int sz = 0;
    int ans = 0;
    for(int i = n;i>=0;i--){
        if(sz%2==0 && mx<=sz/2){
            ans = max(ans, dp[i]);
        }
        mp[v[i]]++;
        mx=max(mx,mp[v[i]]);
        sz++;
    }
    cout<<ans<<"\n";
}


int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1; 
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}; 