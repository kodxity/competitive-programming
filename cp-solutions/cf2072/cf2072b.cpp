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
    string s;cin>>s;
    ll a = 0;
    ll b = 0;
    rep(i,0,n){
        if(s[i]=='-'){
            a++;
        }
        else{
            b++;
        }
    }
    cout<<b * (a/2) * (a/2 + a%2)<<"\n";
 
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