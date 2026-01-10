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
Since everything is connect to 1, the graph is a star graph.

There are two cases: either 1 is the root or some other node is the
root.

We can check if 1 is the root easily: if we do ask_1(1) = sum from
root to 1, if that is an odd number, then the only case is if 1 is
the root, since otherwise n_r + n_1 is even. If 1 is the root, we
know ask_1(1) = n_1, then, n_x = ask_1(x)-n_1 and we're done. 

If 1 is not the root, it is hard because it is impossible to determine
what the root is based on just queries, since n_r is either 1 or -1,
so n_x can = n_r for some other node x, making it impossible to 
differentiate. Thus, we have to determine everything without 
determining what the root actually is. 

Note that ask_1(x) = n_r+n_1+n_x if x != 1,r, ask_1(1) = n_r+n_1, and 
ask_1(r) = n_r. If we make n_r+n_1 = 0, then ask_1(x) = n_x for all 
x != 1. To do this, note ask_1(1) = n_r+n_1. If ask_1(1) = 0, great,
we're done, and we can just do n_x = ask_1(x) for every x. 
If ask_1(1) = 2 or -2, then n_r = n_1 = 1,-1 respectively, so if we
toggle 1, then ask_1(1) = 0. Then, we can proceed to solve for the
value of every node except 1. 

Note we can guess what n_r is. Since ask_1(1) = n_r+n_1, if ask_1(1)=2,
both n_r and n_1 = 1. If ask_1(1)=-2, n_r=n_1 = -1. Else if ask_1(1)=0,
either n_r = 1,n_1 = -1 or n_r = -1,n_1 = 1. However for the last case
we can actually solve for n_r using ask_2. If we toggle 1, then do
ask_1(1), it will either be -2 or 2. Then we know if n_r = -1 or 1. Then,
we just toggle 1 back, and thus the original 1 is the opposite of n_r. 
Thus, we can determine what n_1 is. Thus we've determined every value.

*/




int ask(int x){
    cout<<"? 1 1 "<<x+1<<endl;
    int y;cin>>y;
    return y;
}
void solve(){   
    int n;cin>>n;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
    }
    int ans[n];
    int val = ask(0);
    if((val+2)%2==1){ // 1 is root
        ans[0]=val;
        rep(i,1,n){
            ans[i] = ask(i)-val;
        }
        cout<<"! ";
        rep(i,0,n){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(val == 2){ // root and 1 are both 1
        cout<<"? 2 1"<<endl;
        ans[0]=-1;
    }
    else if(val == -2){// root and 1 are both -1
        cout<<"? 2 1"<<endl;
        ans[0]=1;
    }
    else{
        cout<<"? 2 1"<<endl;
        if(ask(0)==2){ // 1 is -1 originally
            ans[0]=-1;
        }
        else{ // 1 is 1 originally
            ans[0]=1;
        }
        cout<<"? 2 1"<<endl;
    }
    

    rep(i,1,n){
        ans[i] = ask(i);
    }
    cout<<"! ";
    rep(i,0,n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    


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