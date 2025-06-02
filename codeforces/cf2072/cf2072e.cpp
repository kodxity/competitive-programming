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
    vector<pi>ans;
    int cnt = 0;
    int y = 0;
    while(n){
        int lo = 0;
        int hi = 1e4;
        while(lo < hi){
            int mid = lo + (hi-lo+1)/2;
            if(mid * (mid-1)/2 <= n){
                lo = mid;
            }
            else{
                hi = mid-1;
            }
        }
        rep(i,0,lo){
            ans.pb({cnt,y});
            y++;
        }
        cnt++;
        n -= lo * (lo-1)/2;
     
    }
    cout<<ans.size()<<"\n";
    rep(i,0,ans.size()){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
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