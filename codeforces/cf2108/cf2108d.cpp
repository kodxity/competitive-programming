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
Note "It is guaranteed that there are arrays A and B that do not 
contradict the statement, for which the interactor output is correct."
In other words, there always exists some A and B such that condition 
is satisfied.This makes problem much easier, since we don't have to 
check for "bad" arrays.

This means answer is -1 iff there exists multiple valid constructions.
A valid array (A or B) must look like a cycle, so like 123412341234...,
since otherwise by pigeonhole one if the k+1th number != 1st number,
that number length must be < k. So the array will look like
abcdabcd...cdabcdab..., so the position of value x in A mod k is 
different from the position of value x in B mod k. In other words,
let a[i] = a[j] = x. Then i is in A and j is in B iff i%k != j%k. Thus we
can develop a binary search idea to approximate the "break point" between
A and B, since note that if i and j are both in A, then i%k = j%k, so if we
find the first i_j such that i_0%k != i_j%k, where i_0 is the index of the 
first occurance of x (which we know must be in A, since A is at least length 
k, so it contains at least one of every value), then we know that the i_{j-1}
is in A and i_j is the first occurance of x in B. So the break point must
be in between i_{j-1} and i_j.

If we can't get i_j for any x (that is, all j has i_0%k = i_j%k), then all x
has the same mod so the array looks like abcdabcd..., meaning it's cycle
doesn't break. Then, there is only one answer iff n = 2k, in which case we
output k k. Else if n>2k, there is more than 1 answer, so output -1. We can 
get i_j for some x in ~log(1e6) = 20 operations. Note since A and B must both 
contain x for it to be valid, distance from i_{j-1} to i_j is at most 
2k = 100. Thus, we can backtrack from i_j to i_{j-1} and one of them must be 
the break point, so we calculate the first index in B, which will be the size
of A (since 0 indexed). We assign y = i_j and x = i_{j-1} and go through all
[x+1,y]. Note y must be at most n-k-1 since size of B is at least k, and x is
at least k-1 since size of A is at least k. While traversing, let bad[x] be
defined as if the value x has consistent mod throughout. That is i_0%k = i_j%k
for all j that has x as its value. This can be simply checked by asking if
i_{m-1} = x, where i_{n-1} is the last index possible that has the same mod
as i_0. If it is, that means all i_j%k has the same mod, since if it doesn't
then its like i_0%k = i_{m-1}%k, but != some i_j%k, so the mod changed, then
went back, so the array must be split into at least 3 parts (can't be split
into two parts: A and B). If the current index is bad, then if this is the
break point, it means we return -1 since this index can either be in B, or be
in A, and both cases it will be valid. If it's not bad, that means it must 
either be in A or B. We can check if it equals to i_{val,0}%k. If it does,
it's in A, else it's in B. If it's in A, then we know this must be the last
number in A, so we break immediately. If it's in B, we set this as the first
number in B, and continue searching. 
*/




int ask(int x){
    cout<<"? "<<x+1<<endl;
    int y;cin>>y;
    return y;
}
void solve(){   
    int n,k;cin>>n>>k;
    int idx = 0;
    int bad[k+1]={0};
    int md[k+1];
    int cntbad = 0;
    int x = -1;
    int y = -1;
    rep(i,0,k){
        int curr = ask(i);
        vi v;
        md[curr] = i;
        v.pb(i);
        for(int j = k+i;j<n;j+=k){
            v.pb(j);
        }

        int lo = 0;
        int hi = sz(v)-1;
        if(curr == ask(v[sz(v)-1])){
            bad[curr]=1;
            cntbad++;
            continue;
        }
        if(y!=-1){
            continue;
        }
        while(lo < hi){
            int mid = lo + (hi-lo+1)/2;
            if(curr == ask(v[mid])){
                lo = mid;
            }
            else{
                hi = mid-1;
            }
        }
        
        x = v[lo];
        y = v[lo+1];


        
    }
    
    if(cntbad==k){
        if(2*k==n){
            cout<<"! "<<k<<" "<<k<<endl;
                      
        }
        else{
            cout<<"! -1"<<endl;
        }
        return;  
        
    }
    x = max(x, k-1);
    y = min(y,n-k-1);
  
    int ans = y+1;
    while(y != x){
        int val = ask(y);

        if(!bad[val]){
            if(md[val]==y%k){
                break;
            }
            else{   
                ans = y;
            }
        }
        else{
            ans = -1;
        }
        y--;
    }
    
    if(ans==-1){
        cout<<"! -1"<<endl;
        return;
    }
    
    cout<<"! "<<ans<<" "<<n-(ans)<<endl;

    


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