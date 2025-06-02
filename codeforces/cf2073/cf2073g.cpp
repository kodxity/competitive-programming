#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1000000007;


/*
Treat 1 as something that can get deleted.
Treat 0 as something that can get deleted, but a segment of 0 cannot fully 
be deleted. Visiualize as a segment of 0s and 1s. YES if and only if we 
can make it into the exact same sized segments, note 0s can delete 0s and 1s.
Thus, YES iff we can make it so for every pair of matching segments (same value
of 0 or 1), the segment for C size >= segment for B size. Then we can just 
delete freely and get C.

For each segment in C, we go through B greedily (prolly works by inspection).
If C = 1, we try to find a 1 in B that has greater or equal size. If previous
segment is 0 (must be 0 if we're not at the start), we can just delete values
through 0. Else if its at the start and we arrive at a 0 segment when we're 
trying to get a 1 segment, we return NO since we can't delete.
If C = 0, we can delete 1 segments fully so we delete 1 segments and sum up
sizes of 0 segments until sum >= size. 
If all is satisfied, and !(C ends in a 1 segment but B ends in a 0 segment),
we return YES. Else return NO.

WA - If I have a 0 in B, I must have a 0 in C.
*/
void solve(){   
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    a = a + 'f';
    b = b + 'f';
    
    vector<pi> sa;
    vector<pi> sb;
    int cnt = 0;
    rep(i,0,n){
        if(a[i]==a[i+1]){
            cnt++;
        }
        else{
            cnt++;
            sa.pb({a[i]-'0', cnt});
            cnt = 0;
        }
    }

    cnt = 0;
    rep(i,0,m){
        if(b[i]==b[i+1]){
            cnt++;
        }
        else{
            cnt++;
            sb.pb({b[i]-'0', cnt});
            cnt = 0;
        }
    }   

    if(sb[0].first == 1 && sb.size()==1 && sa.size()>1){
        cout<<"no\n";
        return;
    }
    if(sb[0].first == 1){
        if(sa[0].first == 0 || sa[0].second < sb[0].second){
            cout<<"no\n";
            return;
        }
    }
    int it = 0;
    rep(i,0,sb.size()){
        int sum = 0;
        if(sb[i].first == 0){
            int sz = 0;
            while(it < sa.size()){
                if(sz >= sb[i].second){
                    break;
                }
                if(sa[it].first==0){
                    sz += sa[it].second;
                }
                it++;
            }
            if(sz < sb[i].second){
                cout<<"no\n";
                return;
            }
        }
        else{
            int sz = 0;
            
            while(it < sa.size()){
                if(sz >= sb[i].second){
                    break;
                }
                if(sa[it].first==1){
                    sz = sa[it].second;
                }
                it++;
            }
            
            if(sz < sb[i].second){
                cout<<"no\n";
                return;
            }
        }
    }
    
    if(sb[sb.size()-1].first == 1){
        if(sa[sa.size()-1].first == 0 || sa[sa.size()-1].second < sb[sb.size()-1].second){
            cout<<"no\n";
            return;
        }
    }
    cout<<"yes\n";
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