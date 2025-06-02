#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using orderedMultiset = tree<T ,null_type,std::less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int,int,int> tiii;
typedef vector<int> vi;
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
ll MOD = 998244353;


/*

*/

ll qexp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}

ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}  

ll mult(ll x, ll y)
{
    return (x%MOD * 1ll * y%MOD) % MOD;
}
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

    int pos1[n+1]={0};
    int pos2[n+1]={0};
    rep(i,0,n+1){
        pos1[i]=-1;
        pos2[i]=-1;
    }
    int mx = 0;
    rep(i,0,n){
        pos1[a[i]]=i;
        pos2[b[i]]=i;
        mx = max(mx,a[i]);
        mx = max(mx,b[i]);
  
        ll x1 = -1;
        ll x2 = -1;
        if(pos1[mx]!=-1){
           
            x1 = b[i-pos1[mx]];
        }
        if(pos2[mx]!=-1){
       
            x2 = a[i-pos2[mx]];
        }
        cout<<add(qexp(2,mx,MOD),qexp(2,max(x1,x2),MOD))<<" ";
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