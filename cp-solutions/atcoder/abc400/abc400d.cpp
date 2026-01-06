#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define rep(i,a,b) for(int i = a; i<(b);i++)
const int MOD = 1e9+7;

const int MAX_N = 1005;
const int R_CHANGE[]{0, 1, 0, -1};
const int C_CHANGE[]{1, 0, -1, 0};

int row_num;
int col_num;
string building[MAX_N];
bool visited[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

void floodfill(int r, int c) {
	
	stack<pair<int, int>> frontier;
	frontier.push({r, c});
	while (!frontier.empty()) {
		r = frontier.top().first;
		c = frontier.top().second;
		frontier.pop();
        
		if (r < 0 || r >= row_num || c < 0 || c >= col_num || visited[r][c]){
            continue;
        }
			
    
		visited[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int rr = r + R_CHANGE[i];
            int cc = c + C_CHANGE[i];
            int rrr = r + 2*R_CHANGE[i];
            int ccc = c + 2*C_CHANGE[i];
            if (rr < 0 || rr >= row_num || cc < 0 || cc >= col_num){
                continue;
            }
            
            if(building[rr][cc] == '#'){
                dp[rr][cc] = min(dp[rr][cc],dp[r][c]+1);
                if (rrr < 0 || rrr >= row_num || ccc < 0 || ccc >= col_num){
                    continue;
                }
                if(building[rrr][ccc] == '#'){
                    dp[rrr][ccc] = min(dp[rrr][ccc],dp[r][c]+1);
                }
                else{
                    dp[rrr][ccc] = min(dp[rrr][ccc],dp[r][c]+2);
                }
            }
            
			
		}
		for (int i = 0; i < 4; i++) {
			frontier.push({r + R_CHANGE[i], c + C_CHANGE[i]});
		}
	}
}

void solve(){   
    int n,m;cin>>n>>m;
    row_num = n;
    col_num = m;
    rep(i,0,n){
        cin>>building[i];
        rep(j,0,m){
            dp[i][j]=1e9;
        }
    }
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    dp[a][b]=0;
    floodfill(a,b);
    cout<<dp[x][y]<<"\n";
    
}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int t=1; 
 
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}; 