#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1000000007;


/*
Let the treasures have (row, column) = (x1,y1) and (x2,y2).
If scan(0,0), sum is x1+x2+y1+y2. If scan(n,0), sum is n-x1 + n-x2 + y1 + y2.
Thus, scan(0,0) + scan(n,0) = 2(y1+y2)+2n, 
y1+y2 = \frac{scan(0,0) + scan(n,0)-2n}{2}. With this, we can get 
x1+x2 = scan(0,0) - (y1+y2).
We have done 2 operations. We can then find the specific values of x1 and x2
by scan(\frac{x1+x2}{2},0), the middle coordinate. We have
scan(\frac{x1+x2}{2},0) = d1+d2+y1+y2. Subtracting y1+y2, floor(\frac{d1+d2}{2})
is the shorter distance from mid to x1, and ceil(\frac{d1+d2}{2}) is longer 
distance from mid to x2. We can simiarily get y1 and y2 using 1 operation.
We have done 4 operations, and we currently have values x1,x2,y1,y2.
Why limit to 7 operations? This is because we don't yet know orientation.
Test dig(x1,y1) to see if it's a treasure. If yes, dig(x2,y2) and we're done
with 6 operations. Else if (x1,y1) is not a treasure, the treasures are
(x1,y2) and (x2,y1), and we're done with 7 operations.

*/

int scan(int x, int y){
    cout<<"SCAN "<<x+1<<" "<<y+1<<endl;
    int n;cin>>n;
    return n;
}

bool dig(int x, int y){
    cout<<"DIG "<<x+1<<" "<<y+1<<endl;
    bool n;cin>>n;
    return n;
}


void solve(){   
    int n,m;
    cin>>n>>m;
    n--;m--;
    int scan00 = scan(0,0);
    int scann0 = scan(n,0);
    int y1y2 = (scan00 + scann0-2*n)/2;
    int x1x2 = scan00 - y1y2;
    // x1 = floor(\frac{scan(\frac{x1+x2}{2},0)-(y1+y2)}{})
    int distx = scan(x1x2/2,0)-y1y2;
    int x1 = x1x2/2-distx/2;
    int x2 = x1x2-x1;
    int disty = scan(0,y1y2/2)-x1x2;
    
    int y1 = y1y2/2-disty/2;
    int y2 = y1y2-y1;
    if(dig(x1,y1)){
        dig(x2,y2);
    }
    else{
        dig(x1,y2);
        dig(x2,y1);
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