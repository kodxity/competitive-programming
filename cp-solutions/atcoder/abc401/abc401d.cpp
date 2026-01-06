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
    string s;cin>>s;
    int sum = 0;
    rep(i,0,n){
        if(s[i]=='o'){
            k--;
        }
        if(i>0){
            if(s[i-1]=='o'){
                s[i]='.';
            }
        }
        if(i<n-1){
            if(s[i+1]=='o'){
                s[i]='.';
            }
        }
    }

    
    rep(i,0,n){
        if(s[i]=='?'){
            int cnt = 0;
            int j = i;
            while(j<n){
                if(s[j]!='?'){
                    break;
                }
                cnt++;
                j++;
            }
            sum += (cnt+1)/2;
            i=j;
        }
    }

    rep(i,0,n){
        if(s[i]=='?'){
            int sz = 0;
            int j = i;
            while(j<n){
                if(s[j]!='?'){
                    break;
                }
                sz++;
                j++;
            }
            int cnt = 0;
            j=i;
            while(j<n){
                if(s[j]!='?'){
                    break;
                }
                if(sum - (sz+1)/2 + (cnt+1)/2 + (sz-cnt)/2 < k){
                    s[j] = 'o';
                }
                if(sum - (sz+1)/2 + 1 + (cnt)/2 + (sz-cnt-1)/2 < k || k==0){
                    s[j] = '.';
                }
                cnt++;
                j++;
            }
            i=j;
        }
    }
    cout<<s<<endl;
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