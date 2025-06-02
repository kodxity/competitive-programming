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
We must first figure out: given an array, how can we tell it's brilliant?
First, note the final array must look like [mn,mn+1,...mx-1,mx] where mn = min 
and mx = max element in the array. In other words, everything between mn and mx
must be filled.

Playing around with examples, the distinction between arrays that output YES
vs arrays that output NO is not apparent.

Hint 1: maintain an array containing all the difference of between sorted values.
If any of the differences is even, we can always apply the operation and divide
them into two equal parts. Thus, assume all distances are odd.

Hint 2: In the final array (where we can't do any operations), the distances
are all equal. This is because if there exists some adjacent distances that are
not equal, we can always apply operation and create a new element in the array.
Note it will always be odd+odd=even, so we can always apply the operation, until
all differences are equal.

Since the difference is all equal, we canno longer apply operations, since 
doing so will insert a number that already exists in the set. Thus this is the
final form. Let this difference = x. Now look back to the original array of 
differences before applying any operations. We can imagine these differences
be made up of blocks of x. Thus, x must be a divisor of g = gcd(d_1,d_2,...,d_m)
where d_i is the original difference.

If this g = 1, then x must = 1, so the array is brilliant if g = 1. Now, let 
g > 1. Assume we shift the original array a so that the first  element 
a[0] = 0. Then, it must be that all values in a is a multiple of g, because 
they are all a multiple of g distance away from 0 = a[0]. Assume we currently 
have all values in the array be a multiple of g (which is true in the base case,
when we didn't apply any operations yet). Then, let some two numbers = xg and 
yg and we are performing the operation on them. Then, the new number is (x+y)g/2.
Since all d elements is odd, g is odd, so (x+y)/2 is an integer and the new
element is (x+y)/2 * g, which is another multiple of g. Thus, no matter how we
apply the operations, the array a will only contain multiples of g. Thus, the
end array must have d_1=d_2=...=d_m=g. Since g>1, this array is not brilliant.


Thus, an array is brilliant iff g = 1. We can now proceed with the second part
of this problem: how to calculate all subarray satisfying this condition 
efficiently? Usually this is approached by finding the number of valid subarrays
that start at each index i.

Instead of sorting them and finding the difference, note that given a_1,a_2,a_3,
if they are in sorted order and gcd(a_2-a_1,a_3-a_2) = gcd(abs(a_3-a_1),abs(a_1-a_2))
= iff relationship by Euclidean Algorithm. Thus, we don't have to care if they are 
sorted or not. This is the same as finding the absolute difference between each
element of array, then taking the gcd of all the differences in the subarray we're
checking. Thus, a subarray is brilliant iff 
gcd(abs(a_{l+1}-a_{l}),abs(a_{l+2}-a_{l+1}),...,abs(a_r-a_{r-1})) = 1.Note the
more elements we include, the higher the probability of its gcd = 1. Thus, we 
maintain a segtree that can query gcd of segment in O(log(n)). Then, we run
binary search and find the first instance where gcd = 1. Then, all elements 
after it as the ending will be brilliant as well. Thus, we can find this point
in O(log^2(n)).

Also note we must account for dupliate numbers... pain...
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
        return {gcd(a.num,b.num)}; // use formula to merge two items   
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
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    segtree st;
    st.init(n);
    ll ans = 0; 
    ll sz=1; // account for duplicate numbers
    rep(i,0,n-1){
        if(v[i]==v[i+1]){
            sz++;
            continue;
        }
        ans += sz*(sz+1)/2;
        sz=1;
        int x = abs(v[i]-v[i+1]);
        while(x%2==0){
            x/=2;
        }
        st.set(i,x);
    }
    ans += sz*(sz+1)/2;
    
    rep(i,0,n){
        int lo = i;
        int hi = n-1;
        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            if(st.query(i,mid+1).num==1){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        ans += n-1-hi;
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