#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1000000007;


/*

If you can't do any operations, how to immediately tell if we can split 
the sequence (it's valid)? Obviously if the array contains an odd number
of 0s and 1s, it is impossible.
A simple idea is that if we split into segments of continuous 0s and 1s, 
then if size of every segment is even, it is always possible.

I will try to make the claim that given any arrangement such that the 
total sum of 0s and total sum of 1s are both even, it is always possible.
If this is disproved, we've reached closer to the real solution so I'll
take it (hypothesize, then narrow down solution search space).

Say we have some odd sized segments. WLOG we start with 1. We need to 
replace one of the ends with 0. WLOG we choose the right end. We have a 1
now. If the next odd seg be 1. We must now add a 1 to replace a 0. We add
it to the right, and so on, test out examples, etc...

We see that a odd sized 0 or 1 segment can be "fixed" (turned even size) by
both a 0 or a 1, so it doesn't matter the parity.
Now we must prove that if we were to take a 1 from the last index of the
segment, then after satsifying everything else (which is always possible
since partiy doesn't matter), the value that shifts back satisfies the
first segment, then the problem can be solved every time because we keep
taking the last index of the next odd segment and use that as the next 
switch, then proving the bit that comes back will always satisfy the first
segment will this prove its always possible.

This is somewhat difficult to prove, but it looks correct. 
Let 0 = an even segment and 1 = odd segment. We pair up the odd segments
since there must be an even number of them (or else total number of elements
2*n is odd).
For some pair like 10001, the last index number (one we are choosing as
answer for b) will change 4 times since after "fixing" 1, the next 0 is
now odd so we fix that too until the last 1, which is fixed automatically
but the previous 0. Thus, a length n will change n-1 times.
Say the pair is like 101. There is an odd number of 0s so it changes 
even number of times, so parity doesn't change.
Say the pair is 1001, it changes odd number of times, so parity changes. 
Note the number of odd length pairs (even change, doesn't change parity)
can occur any number of times in total, since this pair will have 2 odd
lengths of the same value (0 or 1), thus making the sum even. 
However, the number of even length (change parity) pairs must occur an
even number of times. This is because we have a 0 and a 1 sized odd 
segments, so we need another even lengthed pair to cancel this out again.
As a result, the total number of even lengthed segments is even so in total
it won't change the parity. This means the parity will never change, so 
we've proved it always goes back to the start if we try to satisy everything
using our greedy process of picking the last index and making everything even.
*/

void solve(){   
    int n;cin>>n;
    string s;cin>>s;
    int totalones = 0;
    rep(i,0,2*n){
        totalones += s[i]-'0';
    }
    if(totalones%2){
        cout<<-1<<"\n";
        return;
    }
    s += 'a';
    vi ans;
    int sz = 0;
    int curr = 0;
    bool found = false;
    rep(i,0,2*n){
        sz++;
        if(s[i]==s[i+1]){
            
        }
        else{
            if(sz%2){
                if(!found){
                    found = true;
                    curr = (s[i]-'0');
                    s[i]=(1-(s[i]-'0'))+'0';
                    ans.pb(i);
                    sz=1;
                }
                else{
                    if(s[i]==curr+'0'){
                        s[i+1]=curr+'0';
                        curr = 1-curr;
                        ans.pb(i+1);
                        i++;
                        sz=0;
                    }
                    else{
                        s[i]=curr+'0';
                        curr = 1-curr;
                        ans.pb(i);
       
                        sz=1;
                    }
                }
            }
            
        }
    }
    cout<<ans.size()<<" ";
    rep(i,0,ans.size()){
        cout<<ans[i]+1<<" ";
    }
    cout<<"\n";
    sz = 0;
    rep(i,0,2*n){
        sz++;
        if(sz%2){
            cout<<i+1<<" ";
        }
        if(s[i]!=s[i+1]){
            sz = 0;
        }

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