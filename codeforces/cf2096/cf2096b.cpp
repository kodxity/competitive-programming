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
operations = graphs
loops = -1
*/



void solve(){   
    int n;cin>>n;
    int c[n][n];
    rep(i,0,n){
        rep(j,0,n){
            cin>>c[i][j];
        }
    }

    int a[2][n];
    rep(i,0,2){
        rep(j,0,n){
            cin>>a[i][j];
        }
    }
    ll ans = 0;    
    set<int>st;
    int aj[n][n];
    memset(aj,0,sizeof(aj));
    rep(i,0,n){
        rep(j,0,n-1){
            if(c[i][j]==c[i][j+1]){
                st.insert(j);
                st.insert(j+1);
                aj[j][j+1]=1;
                aj[j+1][j]=1;
            }
            else if(c[i][j]==c[i][j+1]+1){
                if(aj[j][j+1]==1){
                    cout<<-1<<"\n";
                    return;
                }
                aj[j+1][j]=2;
            }
            else if(c[i][j+1]==c[i][j]+1){
                aj[j][j+1]=2;
            }
        }
    }
    int dp[st.size()+1]={0};
    int idx = 1;
    vi v;
    for(auto it = st.begin(); it != st.end(); it++){
        v.pb(*it);
    }

    rep(i,0,v.size()){
        dp[i] += a[0][v[i]];
        if(i+2<v.size()){
            dp[v[i+2]]+=dp[v[i]];
        }
        if(i+1<v.size()){
            if(aj[v[i]][v[i+1]] != 1){
                dp[v[i+1]]+=dp[v[i]];
            }
        }
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