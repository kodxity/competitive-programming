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
    queue<int>q;
    if(n<k){
        cout<<1<<endl;
        return;
    }
    ll sum = k;
    rep(i,0,k){
        q.push(1);
    }
    rep(i,k,n){
        q.push(sum);
  
        int num = q.front();
        q.pop();
        sum *= 2;
        sum -= num;
        sum += 2000000000;
        sum %= 1000000000;
        

    }
    cout<<sum<<endl;
    
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