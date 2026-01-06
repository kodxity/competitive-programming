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
Note it is always more optimal to satisfy the courses by ascending order of time.
Suppose this isn't the case and there exists some construction such that we
satisfied y before x, but x < y in terms of time. Then this must mean that
the tasks satisfying both x and y all occur before deadline x, only that y
was completed first. Thus, we can use the exact same amount of time, and 
switch the x "chunk" and y "chunk" of coursess and achieve the same result (both
completed before reaching deadline x). Thus we proved the base case. Now we
can essentially "earse" x and look at the next deadline. We can apply a similar
reasoning and conclude that for any valid construction, we can always swap
y and x so that the course with the earlier deadline gets completed first.

Now we know order of which courses are completed, problem becomes much easier:
we only need to know for every course, the minimum time it takes to >= 100% that
course, then add it to our total time we spent, then check if that total time is
<= deadline. 

Obviously we need to split each task based on the course it corresponds to. 
Then there is no simple way to greedy this, but note that since percent is
from 0 to 100, we only need 100 states for knapsack dp, which is 100*1e5 = 1e7.
To perform knapsack dp we just loop through each tasks of that course, and
find the minimum time it takes to get 100 or more. 

However, we also need to output the order to the actual tasks used. To do
this we maintain a backtrack array for our knapsack dp (1e7 memory idk why
no MLE but whatever). To backtrack, let bk[i][j] = {x,y} where i is the index
it is currently on, j is the total percent it currently has, x is the index
of the LAST tasks it used up, and y is the value before using the last task
(this is to account for cases where the final value is more than 100, but we
must have j = 100, so we don't know where this value came from after we 
"subtract the previous task value" and backtrack). To perform backtracking,
we let num = current percent, and it = current index. While num > 0, we 
append the index of the last task we added. Then the new num is = y, and the
new index = x-1, since at x we added the task, so we are interested in the
task that we added previous to x (since bk[x][y] = x, which doesn't give us
any info). After backtracking, note we must reverse the array and add it to ans.

*/





void solve(){   
    int n,m;
    cin>>n>>m;
    vector<ll> v(n);
    rep(i,0,n){
        cin>>v[i];
    }

    vector<tiii> a[n];
    rep(i,0,m){
        ll e,t,p;
        cin>>e>>t>>p;
        e--;
        a[e].pb({t,p,i});
        
    }
    vi ans;
    ll sum = 0;
    rep(i,0,n){
        ll dp[101];
        pii bk[sz(a[i])][101];
        memset(bk,0,sizeof(bk));
        dp[0]=0;
        rep(j,1,101){
            dp[j] = 1e9;
        }
        rep(j,0,sz(a[i])){
            
            for(int l = 100;l>=0;l--){
                if(j!=0) bk[j][l] = bk[j-1][l];
                if(dp[l]+get<0>(a[i][j])<dp[min(100,l+get<1>(a[i][j]))]){
                    dp[min(100,l+get<1>(a[i][j]))] = dp[l]+get<0>(a[i][j]);
                    bk[j][min(100,l+get<1>(a[i][j]))] = {j,l};
                }
                
            
            }
        }
        sum += dp[100];
        if(sum > v[i]){
            cout<<"-1\n";
            return;
        }
        int num = 100;
        int it = sz(a[i])-1;
        vi step;
        while(num > 0){
            step.pb(get<2>(a[i][bk[it][num].F]));
            int prevnum = num;
            num = bk[it][num].S;
            it = bk[it][prevnum].F-1;
        }
        reverse(all(step));
        for(auto x : step){
            ans.pb(x);
        }
        

        
    }
    cout<<sz(ans)<<"\n";
    rep(i,0,sz(ans)){
        cout<<ans[i]+1<<" ";
    }
    cout<<"\n";
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