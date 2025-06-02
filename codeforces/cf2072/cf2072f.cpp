#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 2;

void solve(){   
    int n,x;cin>>n>>x;
    rep(i,0,n){
        bool iseven = false;
        for(int j = 0;j<31;j++){
            if(((n-1)&(1<<j))==0 && (i&(1<<j)) > 0){
                iseven = true;
            }
        }
        cout<<x * (iseven==0)<<" ";
        
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