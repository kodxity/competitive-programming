#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1e9+7;

void solve(){   

    int n,k;cin>>n>>k;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    if(n==k){
        int it = 1;
        for(int i = 1;i<n;i+=2){
            if(v[i]==it){
                it++;
            }
            else{
                break;
            }
        }
        cout<<it<<"\n";
    }
    else{
        rep(i,1,n-(k-2)){
            if(v[i]!=1){
                cout<<1<<"\n";
                return;
            }
        }
        cout<<2<<"\n";
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