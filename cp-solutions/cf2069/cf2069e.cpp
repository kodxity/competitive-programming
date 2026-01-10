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

void solve(){   
    string s;cin>>s;
    int n = sz(s);
    int acnt = 0;
    int bcnt = 0;
    rep(i,0,n){
        if(s[i]=='A'){
            acnt++;
        }
        else{
            bcnt++;
        }
    }
    s += s[n-1];
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int it = 0;
    vi aa;
    vi bb;
    int cnt = 0;
    int sz = 1;

    while(it < n && s[it] == s[it+1]){
        it++;
    }
    char start = s[it];
    bool pro = 0;
    while(it < n){
        while(s[it]!=s[it+1]){
            it++;
            sz++;
            pro=1;
            continue;
        }
        if(pro==1){
            if(sz%2==1){
                cnt += sz/2;    
            }
            else{
                if(start == 'A'){
                    aa.pb(sz);
                }
                else{
                    bb.pb(sz);
                }
            }
        }
        
        pro = 0;
        sz=1;
        start = s[it];
        it++;

    }

    int prevc = c;
    int prevd = d;
    sort(aa.begin(),aa.end());
    int left = 0;
    rep(i,0,sz(aa)){
        if(c-aa[i]/2>=0){
            c-=aa[i]/2;
        }
        else{ 
            left += (aa[i]/2-1)-c;
            c = 0;
        }
    }


    sort(bb.begin(),bb.end());
    d = max(0,d-left);
    left = 0;
    rep(i,0,sz(bb)){
        if(d-bb[i]/2>=0){
            d-=bb[i]/2;
        }
        else{ 
            left += (bb[i]/2-1)-d;
            d = 0;
        }
    }

    c = max(0,c-left);
    int tot = 0;
    if(cnt>c){
        cnt -= c;
        c = 0;
    }
    else{
        tot+=cnt;
        cnt=0;
    }
    if(cnt > d){
        cnt -= d;
        d = 0;
    }
    else{
        tot+=cnt;
    }
    tot += prevc-c + prevd-d;
    acnt-=tot;
    bcnt-=tot;
    if(acnt<=a&&bcnt<=b){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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