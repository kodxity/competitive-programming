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
I solved hint 1 + 2 on my own, looked at hint 3.
Hint: Instead of trying to find differences of indexes, note that the cases
is satsified iff there never exists a substring length k that does not have
any of the chosen "case" letters. 

However, an edge case exists: the last letter must be a case, so we will also
consider that separately.

Thus for each length k substring, we can find the mask of the set of all 
letters that it contains. Then, the answer must be a mask such that given any
mask of the substrings, they will have both 1s on at least 1 letter. In other
words, their OR is positive. 

Hint: brute force each subset of letters for answer.

but how to do so in O(1)? Looked at hint 5.
Hint: Instead of finding the answer such that for each substring, at least
one bit is both 1s, we find all masks that can't be the answer. A mask can't be
the answer iff there exists some substring mask, such that our chosen answer 
mask is a submask of ~substring mask (all of the 1s in our answer mask is a 0
in the substring mask).

The problem then turns into the following: Given a set of masks (all 
~substring mask/the inverse of all substring masks), what are all masks that is
a submask of one of the masks in the set? If we can solve this, we can just 
check for each potential answer mask if it's a submask of a "bad" substring
mask in O(1).

This is a classic bitmask dp problem. First set all dp[x] = 1 where x is a 
"bad" mask in the set. Then, we iterate through each mask from biggest to 
smallest, in order to make sure that a mask get processed before all its 
submasks. Then, we can push dp one bit at a time. If x is bad, then all of
x|(1<<i) is a submask of x, where x has the ith bit = 1, thus all of 
x|(1<<i) is bad as well. Thus, it is obvious that every submask can be 
reached this way (since we "erase" one bit each time, so every submask will
be eventually reached). Then after we determined the "bad" values using this
dp, we can find the non-bad value that has the minimum number of bits = answer. 
*/


void solve(){   
    int n,c,k;
    cin>>n>>c>>k;
    string s;cin>>s;
    int cnt[c]={0};
    rep(i,0,k){
        cnt[s[i]-'A']++;
    }
    vi v;
    rep(i,0,n-k){
        int sum = 0;
        rep(j,0,c){
            if(cnt[j]==0){
                sum += (1<<j);
            }
        }
        v.pb(sum);
        cnt[s[i]-'A']--;
        cnt[s[i+k]-'A']++;
    }

    // edge case
    int sum = 0;
    rep(j,0,c){
        if(j != s[sz(s)-1]-'A'){
            sum += (1<<j);
        }
    }
    v.pb(sum);
    
    int dp[(1<<c)]={0};
    rep(i,0,sz(v)){
        dp[v[i]]=1;
    }

    for(int i = (1<<c)-1;i>=0;i--){
        rep(j,0,c){
            if(i&(1<<j)){
                dp[i^(1<<j)]|=dp[i];
            }
        }
    }   
    int ans = c;
    rep(i,0,(1<<c)){
        if(!dp[i]){
            ans = min(ans, __builtin_popcount(i));
        }
    }
    cout<<ans<<"\n";
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