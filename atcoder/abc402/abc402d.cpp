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

*/


void solve(){   
    ll n,m;cin>>n>>m;

    map<ll,ll>mp;
    set<ll>st;
    rep(i,0,m){
        ll x,y;cin>>x>>y;
        ll diff = 1-x;
        y-=diff;
        y+=n;y%=n;
        st.insert(y);
        mp[y]++;
    }
    ll ans = m*(m-1)/2;
    for(auto it = st.begin();it != st.end();it++){
        ans -= mp[*it]*(mp[*it]-1)/2;
    }
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