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
First, it is obvious that we need to know when player 1 wins, given a 
specific subarray game state. Note that plyaer 2 wants to take 0s whenever
they can, since they want to keep as many 1s as possible for themselves and 
eliminate as many 0s as possible so p1 can't take it. 

Consider a cnsecutive segment of 1s. There will always be 0s on both side of 
it until 0s disappear. Thus as long as there is a 0 and a 1 on the board, p2 
can always take 01. This means p1 always takes 00 and p2 always takes 01, 
until one of them runs out. This means after p1 and p2 moves, exactly one 1
and three 0s will be removed. 

Thus, in order for p1 to win, it must be that the number of 0s is at least
2 more than 3 times the number of 1s. In other words, n_0 >= 3n_1 + 2 (note
in the end, p1 must still take 2 so that p2 can't move, so +2). Note that
if this isn't satisfied, p1 will be depleted of 0s, then p1 can just take 11
and win. Note there exists the edge case when after taking one 1 and three 0s 
repeatedly, we are left with 001. In this case, after p1 takes 00, p2 is only
left with 1, so p2 loses. Thus, p1 wins if either n_0 >= 3n_1 + 2, or 
n_0 = 3n_1-1.

We can check each of these cases separately by keeping prefix sum of
n_0 - 3n_1. We can do this by adding 1 when s[i] = 0 and -3 when s[i] = 1.
Then, we iterate through each index i. We must have n_0 >= 3n_1 + 2 
-> n_0 - 3n_1 >= 2 iff pre[i]-pre[j]>=2, so pre[j] satisfies iff 
pre[j] <= pre[i]-2. We can count this in O(logn) using ordered multiset by
always storing pre[i] at each index i, then count is order_of_key(pre[i]-1) 
= counts the number of prefixes < pre[i]-1, so <= pre[i]-2.
For second case, we need n_0-3n_1 = -1, so pre[i]-pre[j]=-1, pre[j] = pre[i]+1.
We can store a map counting the occurance of each prefix value to count this
in O(logn).
*/





void solve(){   
    int n;cin>>n;
    string s;cin>>s;

    int pre[n+1]={0};
    rep(i,0,n){
        pre[i+1]=pre[i]+ (s[i]=='0' ? 1 : -3);
    }

    orderedMultiset <int> ms;
    ms.insert(0);
    map<int,int>mp;
    mp[0]++;
    ll ans = 0;
    rep(i,1,n+1){
        ans += ms.order_of_key(pre[i]-1);
        ans += mp[pre[i]+1];
        ms.insert(pre[i]);
        mp[pre[i]]++;
        
    }
    cout<<ans<<"\n";

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