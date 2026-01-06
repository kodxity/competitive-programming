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
In these problems we need to solve for two tasks: 
- How to solve for the original answer without changes.
- How to update the answer based on changes.

For the first task, the simplest strat (common combo idea) is for each index,
consider how many this index adds to the answer. That is, let this index be
that last element before we change segments, so if it's like 000111, then we
know the third element is the last element before change, and thus it will 
add 1 to the answer. Thus for each index we just need to count how many valid
constructions such that this index is the last element in subsequence before
change. 

WLOG let this index have s[i] = 0 (if s[i] = 1 we do opposite and it's the 
same thing). There are 2^(i-1) subsets the can go before it, that forms some
subsequence (note we must always include the ith element, so subsequence is 
never empty, and since there are i-1 element before this, there are 2^(i-1) 
possible ways to choose). Then proceeding it, the next element in the 
subsequence must be a 1. Let j be some index such that i<j, s[j]=1. This is
a valid index for the next element. Then for this j, we can have 2^(n-j) 
subsets proceeding it that forms a valud subsequence. Thus, in total for some
valid (i,j), there are 2^(i-1) * 2^(n-j) subsequences such that the final
subsequnce include i proceeded by j. 

Thus, the number of subsequences that "i" contributes in total is just
sum_{j \in {i<j, s[j]=1}} 2^(i-1) * 2^(n-j)+1 
= 2^(i-1) * sum_{j \in {i<j, s[j]=1}} 2^(n-j)+1.
Note we +1 since an empty subset is also a valid subset (i is not proceeded
by anything).
We can precompute all 2^(i-1) by letting val[k] = 2^k and query in O(1).
We can also calculate the suffix sum from n to i, containing all 2^j where
s[j] = 1. However, note to account for queries, we must store this in segtree.
Let st1 be this segtree, where we set the value of the ith position to be 
0 if s[i] = 0, and 2^(n-i) if s[i] = 1. Then, sum_{j \in {i<j, s[j]=1}} 2^(n-j)
= st1.query(i,n), since this is the sum of all 2^(n-j) where only s[j] = 1
are counted as sum. Note also that Thus, we can solve for the original ans in O(nlogn).

For the second task, we need to see how to update/adjust ans in queries.
To do this, we must backtrack our ans and pretend that a[x] doesn't exist,
then add the new a[x] back.

To backtrack, we need to subtract all values that "used" a[x] to add to the
total ans. WLOG let s[x] = 0. Then, the ways we used s[x] = 0 to add to total
ans is either we let x = i or x = j. 
If x = i, we must erase its corresponding
2^(i-1) * sum_{j \in {i<j, s[j]=1}} 2^(n-j), which is simple since we can
just query this again and subtract it.
If x = j, we must account for all 1s before it that used this for it's gain,
since after turning this into a 1, the previous 1s cannot use this index as
k anymore. All of the previous 1s added val[n-j] = val[n-x] from this index x.
Thus, we only need to count how many 1s are before x. To do this, we can store
another segtree cnt, since we need to update this as we change bits as well.
Then, let cnt1 = count of 1s, then number of 1s is just cnt0(0,x).

For adding back the new sum, we add the same two previous cases, but make it
the opposite bit, but the general process is the same structure (just differnt
segtrees).

While doing this, note we also have to erase and update the xth element 
inside the cnt and st segtrees as well.
*/

ll add(ll x, ll y)
{
	x += y;
	while(x >= MOD) x -= MOD;
	while(x < 0) x += MOD;
	return x;
}  
 
ll mult(ll x, ll y)
{
	return (x%MOD * 1ll * y%MOD) % MOD;
}



struct SegTree {
    vector<ll> tree;
    ll n;

    SegTree (ll n): tree(2*n, 0), n(n) {}

    void set (ll id, ll val) {
        for (tree[id += n] = val; id > 1; id >>= 1)
            tree[id>>1] = (tree[id] + tree[id^1]) % MOD;
    }

    ll range_sum (ll ql, ll qr) {
        ll ans = 0;
        for (ql += n, qr += n+1; ql < qr; ql >>= 1, qr >>= 1) {
            if (ql&1) (ans += tree[ql++]) %= MOD;
            if (qr&1) (ans += tree[--qr]) %= MOD;
        }
        return ans;
    }
};



void solve(){   
    string s;cin>>s;
    int n = sz(s);
    ll val[n+1]={0};
    val[0]=1;
    
    rep(i,1,n+1){
        val[i]= mult(2,val[i-1]);
    }
    ll ans = 0;
    SegTree st0(n+1); 
    SegTree st1(n+1); 
    SegTree cnt0(n+1); 
    SegTree cnt1(n+1); 
    for(int i = n-1;i>=0;i--){
        if(s[i]=='0'){
            cnt0.set(i,val[i]);
            st0.set(i,val[n-1-i]);
        }
        else{
            cnt1.set(i,val[i]);
            st1.set(i,val[n-1-i]);
        }
    }
    rep(i,0,n){
        if(s[i]=='0'){
            ans = add(ans, mult(val[i], add(1,st1.range_sum(i,n))));
        }
        else{
            ans = add(ans, mult(val[i], add(1,st0.range_sum(i,n))));
        }
    }
    int q;cin>>q;
    while(q--){
        int x;cin>>x;
        x--;
        if(s[x]=='0'){
            // delete 
            st0.set(x,0);
            cnt0.set(x,0);
            ans = add(ans, -mult(cnt1.range_sum(0,x), val[n-1-x])-mult(val[x], add(1,st1.range_sum(x,n))));
            // add
            s[x]='1';
            st1.set(x,val[n-1-x]);
            cnt1.set(x,val[x]);
            ans = add(ans, mult(cnt0.range_sum(0,x), val[n-1-x]) + mult(val[x], add(1,st0.range_sum(x,n))));
        }
        else{
            // delete 
            st1.set(x,0);
            cnt1.set(x,0);
            ans = add(ans, -mult(cnt0.range_sum(0,x), val[n-1-x])-mult(val[x], add(1,st0.range_sum(x,n))));
            // add
            s[x]='0';
            st0.set(x,val[n-1-x]);
            cnt0.set(x,val[x]);
            ans = add(ans, mult(cnt1.range_sum(0,x), val[n-1-x])+mult(val[x], add(1,st1.range_sum(x,n))));
    

        }
        cout<<ans<<" ";

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