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
Looks like classic dp idea.

Let dp[i] be the max ans such that the last segement we used ends at i. For each
i, we must find the last... Actually this dp idea might be sus.

One important observation off the bat is that for each color, we only consider
the segment by the first and last index (the biggest segment). That is, there can
at most be 1 segment for each color. This is because if there are multiple, it
is always not more optimal than if we only have 1 segment. This is because for
any combination of multiple segments, it is possible to create the same "state"
with the 1 segment since we can toggle any elements in between the largest segment,
which contains all combinations subsegments of that color. This is common idea: if
we can prove strat A incoporates every possibility in strat B, we always pick strat
A. Another proof is that having multiple segments have the ability to toggle less
elements, while taking up more "0" space, so it's always less optimal.

Now we have a bunch of egments that never share start or end points. For some 
combination of segments, we can always leave all the end points "0", then color
them optimally after we've colored all the non-endpoints. The observation is that
we always want to use every possible segment iff it's not fully contained in another
segment. Do casework to see this is valid no matter the segment arrangement.

It is left to decide: For each continuous set of segments, what is the minimum 0s
we can have in the segment at the end.
The idea is that for some continuous segments that intersect each other, with
the min and max of the set of segments being l and r, that the answer is just
r-l+1 - cnt where cnt is the number of segments in the subset. Thus, we want to
always increase l,r if possible (or start a new set of segments iff we are forced),
and do so using the minimum possible number of segments.

We sort segments by start index and maintain set as we go along. We must start a
new set iff a[i].left > curr set right index.
Ekse if curr_left < a[i].left < a[i].right < curr_right, the new segment is
completely contained within our subset so to save space (minimize cnt), we don't
add it, so we skip it.
Else if curr_left < a[i].left < curr_right < a[i].right, this is an intersection,
and we want to add this. However by greedy there might be a case where
a_l < b_l < c_l < a_r < b_r < c_r, in this case we processed all 3 segments (adaed
to cnt), when we only needed a and c. Thus, when this happens we do a while loop
and only add the max right index contained within [curr_left...curr_right]. When
implementing this, don't forget we also need to consider the 
curr_left < a[i].left < a[i].right < curr_right case, in which we just skip it.
*/



void solve(){   
    int n;cin>>n;
    vi v(n);
    int mn[n+1]={0};
    int mx[n+1]={0};
    rep(i,0,n+1){
        mn[i]=1e9;
        mx[i]=-1;
    }
    rep(i,0,n){
        cin>>v[i];
        mn[v[i]]=min(mn[v[i]],i);
        mx[v[i]]=max(mx[v[i]],i);
    }

    vector<pii>a;

    rep(i,0,n+1){
        if(mn[i]!=1e9 && mn[i]!=mx[i]){
            a.pb({mn[i]+2,mx[i]+2});
        }
    }
    sort(a.begin(),a.end());
    int cnt = 2;
    int l = 0;
    int r = 1;
    int ans = 0;
    rep(i,0,a.size()){
        if(a[i].F > r){
            ans += r-l+1-cnt;

            cnt = 2;
            l = a[i].F;
            r = a[i].S;
        }
        else if(a[i].S > r){
            int mxr = 0;
            while(!(a[i].F > r) && i<sz(a)){
                if(a[i].F < r && a[i].S > r){
                    mxr = max(mxr,a[i].S);       
                }
                i++;
                
            }
            i--;
            r = mxr;
            cnt++;
        }
        else{
            // ignore
        }
    }
    ans += r-l+1-cnt;
    cnt = 2;
    cout<<ans<<"\n";

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