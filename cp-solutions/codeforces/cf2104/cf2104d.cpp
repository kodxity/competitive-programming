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
typedef vector<int> vi;
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
ll MOD = 998244353;
 

/*
note: used usaco.guide cause vscode doesn't like big mem
*/

vector<ll> prime; 
void sieve(int n){
	bool v[n+1]={0};
	rep(k,2,n+1){
		if(v[k]){ 
			continue;
		}
		for(int x = 2*k;x<=n;x+=k){ 
			v[x]=1;
		}
	}
    ll sum = 0;
	rep(i,2,n+1){
		if(v[i] == 0){
            sum += i;
			prime.pb(sum);
		}
	}
}

void solve(){   
   
    int n;cin>>n;
    ll sum = 0;
    vector<ll> v(n);
    rep(i,0,n){
        cin>>v[i];
        sum += v[i];
    }
    sort(v.begin(),v.end());

    int lo = 0;
    int hi = n-1;
    while(lo < hi){
        int mid = lo + (hi-lo)/2;
        ll cnt = sum;
        rep(i,0,mid){
            cnt -= v[i];
        }

        if(cnt >= prime[n-mid-1]){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }

    cout<<hi<<"\n";
    
}


int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve(6e6);

    int t=1; 
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}; 