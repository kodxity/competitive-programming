    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef vector <int> vi;
    typedef pair<int,int> pi;
    #define pb push_back
    #define rep(i,a,b) for(int i = a; i<(b);i++)
    const int MOD = 1e9+7;
    void solve(){   
        int n,m,k;
        cin>>n>>m>>k;
        vi v;
        int nxt = k;
        rep(i,0,k){
            v.pb(i);
        }
        vi a;
        int cnt[n+1]={0};
        int lo = 0;
        int hi = n+1;
        while(lo < hi){
            int mid = lo + (hi-lo+1)/2;
            if((n/(mid+1)-1)*(mid+1)>=m*(k+1)){
                lo = mid;
            }
            else{
                hi = mid-1;
            }
        }
        rep(i,0,n){
            a.pb(i%lo);
            
        }
        rep(i,0,n){
            cout<<a[i]<<" ";
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