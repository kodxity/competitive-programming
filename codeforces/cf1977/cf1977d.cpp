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

long long rng() { // output a random long long number
	static std::mt19937 gen(
	    std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}
 

/*

*/


void solve(){   
    int n,m;cin>>n>>m;

    map<ll,ll>hsh;
    rep(i,0,n){
        hsh[i]=rng();
    }

    bool a[n][m];
    rep(i,0,n){
        string s;cin>>s;
        rep(j,0,m){
            a[i][j] = s[j]-'0';
        }
    }

    ll val[m]={0};
    rep(j,0,m){
        rep(i,0,n){
            if(a[i][j]){
                val[j]^=hsh[i];
            }
        }   
    }
    map<ll,ll>mp;
    ll ans = 0;
    pii best;
    rep(i,0,n){
        rep(j,0,m){
            mp[(val[j]^hsh[i])]++;
            if(mp[(val[j]^hsh[i])]>ans){
                ans = max(ans,mp[(val[j]^hsh[i])]);
                best = {i,j};
            }
        }
    }

   
    
    cout<<ans<<"\n";
    rep(i,0,n){
        if(i==best.F){
            cout<<1-a[i][best.S];
        }
        else{
            cout<<a[i][best.S];
        }
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