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
typedef pair<int, int> pi;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
ll MOD = 998244353;
 

/*

*/


void solve(){   
    int n;cin>>n;
    vi v(n);
    int sum = 0;
    rep(i,0,n){
        cin>>v[i];
        sum += v[i];
    }
    if(sum==n){
        cout<<"YES\n";
            return;
    }

    rep(i,0,n-1){
        if(v[i]==0&&v[i+1]==0){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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