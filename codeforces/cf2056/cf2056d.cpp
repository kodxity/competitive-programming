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
Was originally thinking about finding the number of "good subarrays" by fixing the 
median (a_1 <= 10), but fixing median means the number of medians values in the 
subarray may vary, since the median is passing through the "block of medians"
is all we know. Thus, there is no fixed length we can rely on for median. I was
also thinking about bruteforcing all 2^10 elements as a subset but this goes
into the same issue. 

Now, imagine if instead of calculating the number of good subarrays, we count
the number of bad subarrays, and subtract from total. Now, note that the median
values are different, meaning its like 1,...,x,x,y,y,...,10 where x and y is
in the middle and x != y. This actually makes it easier to visualize, since
now we know that the number of elements <= x is **exactly half** (note in the
previous approach where we are counting number of good subarrays, size of median
varies, so we can't use this method and thus don't have a strict bound). This
is a big improvement because now when we fix x, all we have to do is find the
subarrays such that number of elements <= x is exactly half of its size. 

This seems difficult, but the idea is very simple: we just use prefix sums.
Add 1 if v[i] <= x, and -1 otherwise. Then, it's half iff the prefix sum of
the segement is 0. This occurs when pre[i] = pre[j], then the segment [i+1,...,j]
is bad (what we want). 

However, the only problem with this is that because we are fixing x, sometimes
it may be that x is not in the subarray at all. Thus, we must not count the
subarrays that doesn't have x in it (else we overcount). A way to do this is
for each index i, let the number of bad arrays is sz(a[x]) where a[x] denotes 
the number of indexes j that have pre[j] = x. Then, we maintain a multiset 
containing all indexes j such that v[j] = x. Then we complementary count the
number of "bad segments" formed by this index i and anothe index j where i<j,
meaning that pre[j] == pre[i], but there is no x inside [i+1,j], which we can
check using the multiset. We then subtract this from a[x] to get the number of
"valid" bad subarrays for a given index. We do this for all indexes, and sum
the answer up in O(nlogn). In the end, we subtract total by the number of 
subarrays (n choose 2).
*/





void solve(){   
    ll n;cin>>n;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }

    
    ll ans = 0;
    rep(k,1,11){
        int pre[n+1]={0};
        map<int,vi> a;
        a[0].pb(0);
        multiset<int>ms;  
        ms.insert(1e9);
        rep(i,0,n){
            if(v[i]<=k){
                pre[i+1]=pre[i]+1;
            }
            else{
                pre[i+1]=pre[i]-1;
            }
            a[pre[i+1]].pb(i+1);
            if(v[i]==k){
                ms.insert(i+1);
            }
        }
        rep(i,0,n){
            int x = pre[i];
            auto it = ms.upper_bound(i);
            auto itr = lower_bound(all(a[x]),*it);
            ans += sz(a[x])-(itr-a[x].begin());
           
        }
        
    }

    cout<<n*(n+1)/2 - ans<<"\n";
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