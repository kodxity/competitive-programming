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

*/



void solve(){   
    int n;cin>>n;
    string s;cin>>s;
    map<int,int>mp;
    int bcnt = 0;
    rep(i,0,n){
        if(s[i]=='B'){
            mp[i+1]=1;
            bcnt++;
        }
    }

    if(mp[1] == 0 && mp[n] == 0){
        cout<<"Alice\n";
        return;
    }
    if(mp[1] == 1 && mp[n] == 1){
        cout<<"Bob\n";
        return;
    }
    if(mp[1] == 0 && mp[n] == 1){
        if(bcnt == 1){
            cout<<"Alice\n";
            return;
        }
        else{
            cout<<"Bob\n";
            return;
        }
        
    }

    // 1 = Bob, n = Alice
    if(mp[n-1]==0){
        cout<<"Alice\n";
    }
    else{
        cout<<"Bob\n";
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