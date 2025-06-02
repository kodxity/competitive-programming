#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1e9+7;

ll sq(ll n){
    ll lo = 0; ll hi = 1e9+1;
    while(lo < hi){
        ll mid = lo + (hi-lo+1)/2;
        if(mid * mid <=n){
            lo = mid;
        }
        else{
            hi = mid-1;
        }
    }
    return lo;
}
void solve(){   

    ll n;cin>>n;
    cout<<ll(sq(n/2))+ll(sq(n/4))<<"\n";
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