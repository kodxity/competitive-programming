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
    int n,k;cin>>n>>k;
    string s;cin>>s;
    int ans[n+1];
    multiset<int> ms[k];
    rep(i,0,n){
        ms[s[i]-'a'].insert(i);
    }

    int cnt = 0;
    set<char>st;
    ans[n]=-1;
    for(int i = n-1;i>=0;i--){
        if(sz(st)==k){
            st.clear();
            cnt++;
        }
        ans[i]=cnt;
        st.insert(s[i]);
    }

    int q;cin>>q;
    while(q--){
        string a; cin>>a;
        int idx = -1;
        rep(i,0,sz(a)){
            auto it = ms[a[i]-'a'].upper_bound(idx);
            if(it == ms[a[i]-'a'].end()){
                idx = n;
                break;
            }
            idx = *it;
        }

        cout<<ans[idx]+1<<"\n";
    }
    
}


int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1; 
    // cin>>t;

    while(t--){
        solve();
    }

    return 0;
}; 