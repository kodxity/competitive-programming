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
    int n;cin>>n;
    vector<pii> v;
    int mx = 0;
    rep(i,0,n){
        int u;cin>>u;
        mx = max(mx, u);
        v.pb({u,i});
    }
    int l = 1;
    int r = n;
    int ans[n]={0};
    rep(j,1,mx+1){
        if(j%2){
            int it1 = 0;
            int it2 = sz(v)-1;
            while(v[it1].F==j){
                ans[v[it1].S]=r;
                r--;
                it1++;
            }
            while(v[it2].F==j){
                ans[v[it2].S]=r;
                r--;
                it2--;
            }

            rep(i,it1,it2+1){
                if(v[i].F==j){
                    ans[v[i].S]=r;
                    r--;
                }
            }

        }
        else{
            int it1 = 0;
            int it2 = sz(v)-1;
            while(v[it1].F==j){
                ans[v[it1].S]=l;
                l++;
                it1++;
            }
            while(v[it2].F==j){
                ans[v[it2].S]=l;
                l++;
                it2--;
            }

            rep(i,it1,it2+1){
                if(v[i].F==j){
                    ans[v[i].S]=l;
                    l++;
                }
            }
        }

        vector<pii> a;
        rep(i,0,sz(v)){
            if(v[i].F != j){
                a.pb(v[i]);
            }
        }
        v=a;
        
    }
    rep(i,0,n){
        cout<<(ans[i] == 0 ? l : ans[i])<<" ";
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