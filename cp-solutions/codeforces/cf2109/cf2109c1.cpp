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
    rep(i,0,2){
        cout<<"digit"<<endl;
        int x; cin>>x;
    }
    int a,b,c,d;
    cout<<"add -8"<<endl;
    cin>>a;
    cout<<"add -4"<<endl;
    cin>>b;
    cout<<"add -2"<<endl;
    cin>>c;
    cout<<"add -1"<<endl;
    cin>>d;
    cout<<"add "<<n-1<<endl;
    int x;cin>>x;
    cout<<"!"<<endl;
    cin>>x;
    
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