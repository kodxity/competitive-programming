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
These construction problems will probably follow some fixed procedure that 
breaks the entire problem into sub problems, solving the subproblems, then 
merging everything together to solve the full problem, and it will do so by
following a fixed pattern that works for every subproblem without changing
anything else. 


*/


void solve(){   
    int n,m;cin>>n>>m;

    vector<vi>ans;
    map<pii,int>mp;
    bool bad = 0;
    rep(i,0,m){
        int a,b;cin>>a>>b;
        if(mp[{b,a}]){
            bad = 1;
            break;
        }
        mp[{a,b}]=1;
        vi v;
        v.pb(a);
        v.pb(b);
        rep(j,1,n+1){
            if(j!=a && j!=b){
                v.pb(j);
            }
        }
        ans.pb(v);
        v.clear();
        for(int j = n;j>=1;j--){
            if(j!=a && j!=b){
                v.pb(j);
            }
        }
        v.pb(a);
        v.pb(b);
        ans.pb(v);
    }

    if(bad){
        cout<<"NO\n";
        return;
    }



    cout<<"YES\n";
    cout<<sz(ans)<<"\n";
    rep(i,0,sz(ans)){
        for(auto x : ans[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }




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