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
    vi a(n);
    vi b(n);
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        cin>>b[i];
    }
    int bad = 0;
    map<pi,int>mp;
    map<int,int>go;
    int cnt = 1;
    rep(i,0,n){
        go[a[i]]=b[i];
        if(a[i]==b[i]){
            bad++;
            mp[{a[i],b[i]}]=n/2+1;
        }
        if(mp[{a[i],b[i]}]==0){
        
            mp[{a[i],b[i]}] = cnt;
            mp[{b[i],a[i]}] = cnt;
            cnt++;
          
        }
    }
    vi v;
    rep(i,1,n+1){
        if(go[go[i]]!=i){
            cout<<-1<<"\n";
            return;
        }
    }
    int idx[n+1]={0};
    rep(i,0,n){
        v.pb(mp[{a[i],b[i]}]);
    
        idx[v[i]]=i;
    }
   
    vector<pi>ans;
    if(n%2){
        if(bad>1){
            cout<<-1<<"\n";
            return;
        }
        rep(i,0,n/2+1){
            if(i != idx[i+1]){
                ans.pb({i,idx[i+1]});
                idx[v[i]]=idx[i+1];
                swap(v[i],v[idx[i+1]]);
            }
            
        }
        rep(i,n/2+1,n){
            idx[v[i]]=i;
        }
        int val = n/2;
        rep(i,n/2+1,n){
            if(i != idx[val]){
                ans.pb({i,idx[val]});
                idx[v[i]]=idx[val];
                swap(v[i],v[idx[val]]);
            }
            
            val--;
        }
    }
    else{
        if(bad>0){
            cout<<-1<<"\n";
            return;
        }
        rep(i,0,n/2){
            if(i!=idx[i+1]){
                ans.pb({i,idx[i+1]});
                idx[v[i]]=idx[i+1];
                swap(v[i],v[idx[i+1]]);
            }
            
        }
        rep(i,n/2,n){
            idx[v[i]]=i;
        }
        int val = n/2;
        rep(i,n/2,n){
            if(i != idx[val]){
                ans.pb({i,idx[val]});
                idx[v[i]]=idx[val];
                swap(v[i],v[idx[val]]);
            }
           
            val--;
        }
        
    }
    cout<<ans.size()<<"\n";
    rep(i,0,ans.size()){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
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