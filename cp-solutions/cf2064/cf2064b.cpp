#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1e9+7;
void solve(){   
    int n;cin>>n;
    vector<ll> v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    rep(i,1,n){
        if(v[i]%v[0]==0){
           ans= gcd(ans,v[i]/v[0]);
        }
    }

    cout<<((ans==1) ? "Yes\n" : "No\n");
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