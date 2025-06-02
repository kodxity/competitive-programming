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
    string s;cin>>s;
    int ans = 0;
    s = '0'+s;
    rep(i,0,n){
        if(s[i]!=s[i+1]){
            ans++;
        }
    }
    if(ans<=1){
        cout<<n+ans<<"\n";
    }
    else if(ans==2){
        
        cout<<n+ans-1<<"\n";
    }
    else{
        cout<<n+ans-2<<"\n";
    }

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