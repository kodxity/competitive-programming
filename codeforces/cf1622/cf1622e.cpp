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

We eliminate absolute value signs and brute force 2^10 expressions. Now we have 
the x_i fixed for all people and we only focus on the actual score of everyone. 
Note instead of computing each individual person which can become unorganized 
and confusing, we can instead focus on each position. 

At each position note we add 1 if someone has 1 at that position and currently 
their actual score is positive, and do -1 otherwise. Then it is obvious to sort 
the positions by their total value in the end in ascending order, then assign 
the smallest value position (might be negative) to 1 and the largest value to m, 
since we want to maximize the total value.

The main problem that’s stopping me from implementing this approach (and what 
makes this problem sus) is that sometimes, we may assign values in such a way 
that k_i > x_i (where k_i is a persons actual score) but we have done x_i - k_i 
in our equation (but absolute value means we were supposed to do k_i - x_i), or 
vice versa. It is possible to construct such cases.

However, note we can disprove that a “invalid” case will always not be optimal 
(maximum). WLOG we encounter a case such that even when we assign k_i as 
positive, we forced it to be smaller than x_i in our final assignment. This is 
invalid. However, note when we keep everything the same but invert this person 
so that their expression is x_i - k_i (k_i is now negative). Then, k_i will 
ever be larger than the previous k_i (before we inverted) since all we did was 
make every position -1 instead of 1, which only decreases its value in the 
final sort, meaning that it’s also smaller than x_i, so x_i - k_i is positive 
which is what we wanted. Then, note we will always prefer this “valid” way over 
an “invalid” way when calculating answer, since we want it to be as large as 
possible (note if we want minimum suppose value, we can’t do this to solve the 
problem since sometimes an invalid way is preferred). 

Thus, we can brute force normally and not worry about the answer being an 
“invalid” assignment, since we can always make a “valid” arrangement better 
than it.

*/



void solve(){   
    
    int n,m;cin>>n>>m;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    int a[n][m];
    rep(i,0,n){
        string s;cin>>s;
        rep(j,0,m){
            a[i][j] = s[j]-'0';
        }
    }
    ll mx = 0;
    int key = 0;
    rep(i,0,(1<<n)){
        int val[m]={0};
        ll sum = 0;
        rep(j,0,n){
            if(((1<<j) & i)){
                sum -= v[j];
                rep(l,0,m){
                    val[l]+=a[j][l];
                }
            }
            else{
                sum += v[j];
                rep(l,0,m){
                    val[l]-=a[j][l];
                }
            }
        }
        vi sr;
        rep(j,0,m){
            sr.pb(val[j]);
        }
        sort(sr.begin(),sr.end());
        rep(j,0,m){
            sum += sr[j] * (j+1);
        }
        if(sum > mx){
            mx = sum;
            key = i;
        }
    
    }


    int val[m]={0};
    rep(j,0,n){
        if(((1<<j) & key)){
            rep(l,0,m){
                val[l]+=a[j][l];
            }
        }
        else{
            rep(l,0,m){
                val[l]-=a[j][l];
            }
        }
    }
    vector<pii> sr;
    rep(j,0,m){
        sr.pb({val[j],j});
    }
    sort(sr.begin(),sr.end());
    int ans[m];
    rep(i,0,m){
        ans[sr[i].S] = i+1;
    }
    rep(i,0,m){
        cout<<ans[i]<<" ";
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