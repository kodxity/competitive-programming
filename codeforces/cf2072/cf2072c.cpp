#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1e9+7;
void solve(){   

    int n,x;cin>>n>>x;
    int num = 0;
    rep(i,0,30){
        if((x & (1<<i))==0){ 
            break;
        }
        else{
            num += (1<<i);
        }
    }

    int k = min(num+1,n-1);
    int ans = 0;
    rep(i,0,k){
        cout<<i<<" ";
        ans |= i;
    }
    if((ans|k) == x){
        cout<<k<<" ";
    }
    else{
        cout<<(x^ans)<<" ";
    }
    
    rep(i,k+1,n){
        cout<<0<<" ";
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