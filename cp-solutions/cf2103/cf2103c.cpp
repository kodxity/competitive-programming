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


*/


void solve(){   
    int n,k;cin>>n>>k;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    bool ans = false;
    int cnt1 = 0;
    int cnt2 = 0;
    int val = 0;
    int sz = 0;
    int it = 0;
    rep(i,0,n){
        sz++;
        if(val==0){
            if(v[i]<=k){
                cnt1++;
            }
            if((sz+1)/2 <= cnt1){
                if(cnt1>sz-cnt1 && i<n-1){
                    if(v[i+1]>k){
                        i++;
                    }
                }
                val++;
                sz=0;
            }
        }
        else if(val==1){
            if(v[i]<=k){
                cnt2++;
            }
            if((sz+1)/2 <= cnt2){
                val++;
                it = i;
                break;
            }
        }
    }
    if(val==2 && it != n-1){
        ans = true;
    }

    cnt1 = 0;
    cnt2 = 0;
    val = 0;
    sz = 0;
    it = 0;
    reverse(all(v));
    
    rep(i,0,n){
        sz++;
        if(val==0){
            if(v[i]<=k){
                cnt1++;
            }
            if((sz+1)/2 <= cnt1){
                if(cnt1>sz-cnt1 && i<n-1){
                    if(v[i+1]>k){
                        i++;
                    }
                }
                val++;
                sz=0;
            }
        }
        else if(val==1){
            if(v[i]<=k){
                cnt2++;
            }
            if((sz+1)/2 <= cnt2){
                val++;
                it = i;
                break;
            }
        }
    }
    if(val==2 && it != n-1){
        ans = true;
    }
    cnt1 = 0;
    cnt2 = 0;
    val = 0;
    sz = 0;
    it = 0;
    rep(i,0,n){
        sz++;
        if(val==0){
            if(v[i]<=k){
                cnt1++;
                
            }
            if((sz+1)/2 <= cnt1){
                val++;
                it = i;
                break;
            }
        }
        
    }
    sz = 0;
    for(int i = n-1;i>it+1;i--){
        sz++;
        if(val==1){
            if(v[i]<=k){
                cnt2++;
            }
            if((sz+1)/2 <= cnt2){
                val++;
                break;
            }
        }
    }
    if(val==2){
        ans = true;
    }
    
    cout<<(ans==true ? "YES\n" : "NO\n");
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