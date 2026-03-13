
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define rep(i,a,b) for(int i = a;i<(b);++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

int main(){
    ll n,p;
    cin>>n>>p;
    vector<pair<ll,ll>>v;
    rep(i,0,n){
        ll x,y;
        cin>>x>>y;
        v.pb({x,y});
    }
    map<tuple<ll,ll,ll>,ll>mp;
    ll ans = 0;
    map<ll,ll>mid;
    rep(i,0,n){
        rep(j,i+1,n){
            
            ll x1 = v[i].first;
            ll y1 = v[i].second;
            ll x2 = v[j].first;
            ll y2 = v[j].second;

            if(y1==y2){
                ll middle = x2+x1;
                mid[middle]++;
                ans = max(ans, mid[middle]);
            }
            else{
                ll ma = y2-y1;
                ll mb = x2-x1; 
                ll g = gcd(ma,mb);
                ma /= g;
                mb /= g;
                ll b = ma * (y1+y2) + mb * (x1+x2);
                mp[{ma,mb,b}]++;
                ans = max(ans, mp[{ma,mb,b}]);
                // cout<<mp[{ma,mb,b}]<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<ma<<" "<<mb<<" "<<b<<endl;
            }
            

        }
    }
    // cout<<ans<<" "<<n<<" "<<p<<endl;
    cout<<((ans*2*100 >= p*n) ? "YES\n" : "NO\n");
    return 0;
} 

