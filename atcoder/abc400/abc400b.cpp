#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1e9+7;
void solve(){   

    int n,m;cin>>n>>m;
    ll ans = 0;
    ll r = 1;
    rep(i,0,m+1){
        ans += r;
        r*=n;
        if(ans>1e9){
            cout<<"inf\n";
            return;
        }
    }
    
    cout<<ans<<endl;
}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int t=1; 
 
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}; 