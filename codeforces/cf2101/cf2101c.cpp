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
Hint: consider each index individually. What is the maximum number
of pairs that cross this index?

let's calculate the answer by summing up answer for each index. Let's
add 1 to each index if we have pair y-x, and index i is between [x,y-1].
Then the sum of ans of index is the final ans. 

For each index, we can calculate how many (the max possible) pairs we 
can form such that i is in between x and y. First, lets find how many
pairs before and include i, and after i, such that we can assign it
to some number without breaking the previous assignments. The only
condition is that for some a[i], the value x assigned to it has a[i]>=x.
It is best to greedily assign it to the maximum available number <= a[i], 
that has not previously been chosen. This is easy, as we can just simulate 
it starting from the first number using a set, and erasing the number that 
we picked from the set. Note we should always choose a number if possible, 
since it doesn't matter and the earlier a number is chosen, the better
(we don't care who chose it, only that it's chosen). Also, if we can't 
assign any number to it, it means all numbers <= a[i] has already been
assigned, so we can't possibly assign anything else to it without breaking
something previously. 

So for some i, we can simulate choosing the number from [0,i] and 
[i+1,n]. Let the number of chosen numbers be x and y respectively, 
then the maximum possible "score" for this index is min(x,y), because
if a pair adding 1 to i, i must be between it, so for every x we pair
it up with a y (other side). Now this is the best case scenario, but
does it really work for all indexes? 

First we prove that given some chosen numbers set X and Y, we can always
only use 1...min(sz(X),sz(Y)) and assign them to numbers from both sets,
and get a valid pairing without breaking anything. So X contains some 
numbers x_1,x_2,...,x_k, and same with Y. WLOG let sz(X) < sz(Y). Then
note each element in X and Y must be distinct, so we can sort them. Then,
we know in the sorted array x_1,x_2,...,x_k, x_1>=1, x_2>=2,..., x_k >=k 
since otherwise they aren't distinct (just imagine x_1,x_2,...,x_k on a 
number line, and we are pushing them "down" until they fill up positions
1...k). Thus, it is always possible to assign them to 1...k based on their
sort order of the value they're assigned. Same with Y. Thus, we've proven
for some set X and Y, we can always find a pairing to pair up (and we can
know the pairing by sorting it, but it's not nessesary for this problem).

The only other thing we need to solve for is the maximum answer we can have. 
The followingidea is illustrated by Mcpqndq, which helped me understand: Note
the size of X (max possible starts) will always increase, and size of Y 
(max possible ends) will always decrease. Since sz(X) starts from 0 and 
sz(Y) starts from some m, there is a point in time when sz(X) = sz(Y) so 
close to equal. Let this point be the "break" point. Then, we assign all 
indexes in X (at this time) as a start, and all indexes in Y (at this time) 
as a end. Then this arrangement will yield the maximum answer. Why is this
true? Well, recall for each index the maximum score is min(sz(X),sz(Y)). 
When we have i such that sz(X) < sz(Y), we assigned all elements in X as
a start point. Since X <= i < breakpoint <= Y, we know that every X we've
came across at this point will match with a Y on the other side, and 
all X < i < all Y, meaning that in the construction described we will add 
sz(X) = min(sz(X),sz(Y)) to answer from this index, which is the max we 
can get. If i such that sz(X) > sz(Y), all end points match to a start 
point and X <= breakpoint < i <= Y, so again all X < i < all Y, meaning 
we add sz(Y) = min(sz(X),sz(Y)). So for every case (every index), we add
min(sz(X),sz(Y)) for this construction, which also happens to be the 
maximum score we can possibly add. Thus, we've proven that this 
construction yields the maximum possible answer no matter the pairing. 

For this problem, we only need to find the max ans, and since we've proven
we can always take min(sz(X),sz(Y)) for each index and there exists such
a construction that satisfies this for all indexes, we can simply just add
min(sz(X),sz(Y)) for each i and sum the answer. 
*/


void solve(){   
    int n;cin>>n;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }

    int pre[n];
    set<int>st;
    rep(i,0,n){
        st.insert(i+1);
    }
    int sum = 0;
    rep(i,0,n){
        auto it = st.upper_bound(v[i]);
        if(it != st.begin()){
            --it;
            st.erase(it);
            sum++;
        }
        pre[i]=sum;
    }
    int suf[n+1]={0};
    st.clear();
    rep(i,0,n){
        st.insert(i+1);
    }
    sum = 0;
    for(int i = n-1;i>=0;i--){
        auto it = st.upper_bound(v[i]);
        if(it != st.begin()){
            --it;
            st.erase(it);
            sum++;
        }
        suf[i]=sum;
    }

    ll ans = 0;
    rep(i,0,n){
        ans += min(pre[i],suf[i+1]);
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