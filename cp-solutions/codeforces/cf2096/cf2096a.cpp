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
    int n;cin>>n;
    string s;cin>>s;
    reverse(s.begin(),s.end());
    int l = 1;
    int r = n;
    vi ans;
    rep(i,0,n-1){
        if(s[i]=='>'){
            ans.pb(r);
            r--;
        }
        else{
            ans.pb(l);
            l++;
        }
    }    
    ans.pb(l);
    reverse(ans.begin(),ans.end());
    rep(i,0,n){
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