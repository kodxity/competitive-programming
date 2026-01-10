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
A is lexiographically smaller than b iff there is a prefix where they are the same
and the letter after the prefix has a[i] < b[i]. There is no easy way to calculate
answer at face value, so we must brute force i. For each i, we either have a[i]<b[i]
(we stop), or a[i] = b[i] (we continue). We can brute force all letters <= b[i] in
at most 26. Then note the best strategy is to greedily take the first occurance
of that letter (minimum distance). We prove this by contradiction. Let us have 
i < x < y where x,y are indexes of the desired letter. We want to prove it is
always not less optimal to pick x first. If we pick y first, there is a point
where y = x+1 during travelling. Then, moving y to i is the same as moving y
to x, then moving x to i. Thus, in the end we still moved x to i, and if this
was optimal then later we can just move y to x and achieve the same result. Thus,
every possible optimal sequence of moves stems from moving x to i. 

To simulate moving, we must calulate the distance between i and x where x is
the shortest distance for all letters (in O(1)). Moreover, we must update each
position after moving the letter a[i] = b[i] to i and shifting all other letters
[i+1...x-1] by 1. 

I was originally thinking of a lazy seg idea where we store positions of each 
letter, update range +1, then using binary search to query position, but 
this is very tedious and requires log^2n which probably can't pass. 
A simpler/smarter way is that instead of storing the actual indexes of letters, '
we find the distance from it to i at every instance and update accordinly. We 
let the distance of letter **originally** at index x have distance pre[x]. 
Initially, each element in segtree has value 1, so element 1 is 1 dist away, 2 
is 2 dist away, etc. To query  dist, it is just st.sum(0,x+1). To shift distances 
after we take a[i] = b[i], we just set position x to 0 (st.set(x,0)), so that
when calculating the prefix sum, we ignore this element as we already taken it.
Thus, the letters will still remain in the same order when calculating prefix sum.
*/

struct item{
    ll num;
};
 
struct segtree{
    int sz;
    vector <item> val; // store sum of nodes    
    item neutral = {0}; // EMPTY SEGMENT: we can add this element 
    // to anything and get the original result 
    item merge(item a, item b){ // merge two nodes( their items)
        return {a.num + b.num}; // use formula to merge two items   
    }
    item single(ll v){ // we are left with single node( base case)
        return {v}; 
    }

    void init(int n){ // create empty segtree with length at least n increased to closest power of 2(for leaves of binary tree)
        sz = 1;
        while(sz < n){
            sz *= 2;
        }
        val.assign(2*sz,neutral); // create empty segtree size 2*sz and fill with 0s
    }
    void set(int i, ll u){
        set(i,u,0,0,sz);
    }
    void set(int i, ll u, int x, int lx, int rx){
        if(rx-lx==1){ // current node is a leaf
            val[x] = single(u);
            return;
        }
        int m = (lx+rx)/2; // mid
        if(i < m){ // left subtree
            set(i, u, 2*x+1,lx,m);
        }
        else{ // right subtree
            set(i, u, 2*x+2,m,rx);
        }
        val[x] = merge(val[2*x+1], val[2*x+2]);
    }
    item query(int l, int r){
        return query(l,r,0,0,sz);
    }
    item query(int l, int r, int x, int lx, int rx){
        if(r <= lx || rx <= l){ // outside range
            return neutral;
        }
        if(l <= lx && rx <= r){ // inside range
            return val[x];
        }
        int m = (lx+rx)/2;
        item osa = query(l,r,2*x+1,lx,m);
        item nosa = query(l,r,2*x+2,m,rx);
        return merge(osa, nosa);
    }
 
};


void solve(){   
    int n;cin>>n;
    string a,b;
    cin>>a>>b;
    
    vi v[26];
    int idx[26]={0};
    rep(i,0,n){
        v[a[i]-'a'].pb(i);
    }
    segtree st;
    st.init(n);
    rep(i,0,n){
        st.set(i,1);
    }


    ll ans = 1e18;
    ll cnt = 0;
    rep(i,0,n){
        rep(j,0,b[i]-'a'){
            if(idx[j] < sz(v[j])){
                ans = min(ans, cnt + st.query(0,v[j][idx[j]]+1).num-1);
            }
        }
        if(idx[b[i]-'a']<sz(v[b[i]-'a'])){
            cnt += st.query(0,v[b[i]-'a'][idx[b[i]-'a']]+1).num-1;
            st.set(v[b[i]-'a'][idx[b[i]-'a']],0);
            idx[b[i]-'a']++;
            
        }
        else{
            break;
        }
    }

    if(ans==1e18){
        cout<<-1<<"\n";
        return;
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