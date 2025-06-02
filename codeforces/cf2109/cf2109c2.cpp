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
There are at most 9 digits (exccept 1e9 but we don't worry abt that) in
x, so there are at most 10 digits in 9*x. 

The sum of digits of every multiple of 9 is a multiple of 9. Thus, 
S(9x) is a multiple of 9. Furthermore, S(9x) <= 9*10 = 90, since max
case there are 10 digits and each of them is 9. Thus, S(9x) is a 2
digit multiple of 9.

The thing with 2 digit multiples of 9 is that 18,27,36,...,81,90 all
have S(n) = 9 (sum of their digits is exactly 9). Thus, in 3 operations
we can make any number equal to 9. That is, S(S(9x)) = 9 is always true
for any x. 

Then finally, we just add n-9 and finish.
*/


void solve(){   
    int n;cin>>n;
    int a,b,c,d;
    cout<<"mul 9"<<endl;
    cin>>a;
    cout<<"digit"<<endl;
    cin>>b;
    cout<<"digit"<<endl;
    cin>>c;
    cout<<"add "<<n-9<<endl;
    int x;cin>>x;
    cout<<"!"<<endl;
    cin>>x;
    
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