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
typedef pair<int, int> pi;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
ll MOD = 998244353;
 

/*
Hint: get sum of all lengths of words.
This is easy, just binary search and find the smallest w such that
h = 1 in ~20 operations.
Let S be the length including spaces. How does this help us though?

Hint: Given a height, how many "good" widths are there?
Note the answer is at most S (set upper bound) since we can just go 
1 * S. 
For some given h, if everything works perfectly, we don't need any 
spaces in the end and area is S-h+1. Else, if h*w>S, we know this is
not optimal. 
Thus, the range of answers lie only in [S-h+1,S] for some given h.

The "smart" thing about this bound is that since answer is h*w and
in [S-(h-1), S], there exists EXACTLY ONE w such that answer is in
bounds and is a multiple of h, since the bound contains everything
mod h exactly once. Thus, we can find this w using math, and see if
asking this w gives back h. If it does, we update answer. Going 
through all possible h (at most n), finding designated w, and seeing
if it matches, then if it does we take it, will yield final answer.

*/

int ask(int n){
    cout<<"? "<<n<<endl;
    int x;cin>>x;
    return x;
}

void solve(){   
    int n;cin>>n;

    int lo = 1;
    int hi = 1e9;
    while(lo < hi){
        int mid = lo + (hi-lo)/2;
        if(ask(mid)==1){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    int s = hi;
    int ans = s;
    rep(i,1,n+1){
        if(ask(s/i) == i){
            ans = min(ans, s/i * i);
        }
    }
    cout<<"! "<<ans<<endl;
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