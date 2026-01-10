#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1e9+7;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using orderedMultiset = tree<T ,null_type,std::less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
void solve(){   

    int n;cin>>n;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    
    int ans[n][n];
    memset(ans,0,sizeof(ans));
    int mx = 0;
    rep(j,0,n){

        orderedMultiset<int>ms;
        for(int i = j;i>=0;i--){
       
            ans[i][j]=ms.order_of_key(v[i]) - (ms.size()-ms.order_of_key(v[i]+1));
     
            ms.insert(v[i]);
            mx = max(mx,ans[i][j]);

        }
    }
    
    rep(i,0,n){
        rep(j,0,n){
            if(ans[i][j]==mx){
                cout<<i+1<<" "<<j+1<<"\n";
                return;
            }
        }
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