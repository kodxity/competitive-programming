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

class Tree {
  private:
	const int root = 0;

	const vector<vector<int>> &adj;
	const int log2dist;
	vector<int> par;
	vector<vector<int>> pow2ends;
	vector<int> depth;

	/** use DFS to calculate the depths and parents of each node */
	void process(int at, int prev) {
		depth[at] = depth[prev] + 1;
		for (int n : adj[at]) {
			if (n != prev) {
				process(n, at);
				par[n] = at;
			}
		}
	}

  public:
	Tree(const vector<vector<int>> &adj)
	    : adj(adj), log2dist(std::ceil(std::log2(adj.size()))), par(adj.size()),
	      pow2ends(par.size(), vector<int>(log2dist + 1)), depth(adj.size()) {
		par[root] = depth[root] = -1;
		process(root, root);

		
		// pow2ends[n][k] contains the 2^kth parent of node n
		// if there is no 2^kth parent, the value is -1
		for (int n = 0; n < par.size(); n++) { pow2ends[n][0] = par[n]; }
		for (int p = 1; p <= log2dist; p++) {
			for (int n = 0; n < par.size(); n++) {
				int halfway = pow2ends[n][p - 1];
				if (halfway == -1) {
					pow2ends[n][p] = -1;
				} else {
					pow2ends[n][p] = pow2ends[halfway][p - 1];
				}
			}
		}
	}

	/** @return the kth parent of node n */
	int kth_parent(int n, int k) {
		int at = n;
		// break down k into powers of 2 by looping through its bits
		for (int pow = 0; pow <= log2dist; pow++) {
			if ((k & (1 << pow)) != 0) {
				at = pow2ends[at][pow];
				if (at == -1) {
					break;  // stop when we're past the root
				}
			}
		}
		return at;
	}

	/** @return the LCA of nodes n1 and n2 */
	int lca(int n1, int n2) {
		if (depth[n1] < depth[n2]) { return lca(n2, n1); }
		// lift n1 up to the same height as n2
		n1 = kth_parent(n1, depth[n1] - depth[n2]);
		if (n1 == n2) {
			return n2;  // in this case, n2 is a direct ancestor of n1
		}

		// move the nodes up as long as they don't meet
		for (int i = log2dist; i >= 0; i--) {
			if (pow2ends[n1][i] != pow2ends[n2][i]) {
				n1 = pow2ends[n1][i];
				n2 = pow2ends[n2][i];
			}
		}
		// at this point, the lca will be the parent of either node
		return pow2ends[n1][0];
	}

	/** @return the distance between nodes n1 and n2  */
	int distance(int n1, int n2) {
		return depth[n1] + depth[n2] - depth[lca(n1, n2)] * 2;
	}
};

void solve(){   
    int n,q;cin>>n>>q;
    vector<vi> aj(n+1);
    aj[0].pb(1);
    rep(i,2,n+1){
        int u;cin>>u;
        aj[u].pb(i);
    }
    Tree tree(aj);
    map<pii,bool>mp;
    rep(i,0,n){
        for(auto x : aj[i]){
            mp[{i,x}]=1;
        }
    }
    vi v(n+1);
    v[0]=0;
    rep(i,1,n+1){
        cin>>v[i];
    }
    set<int>bad;
    auto check = [&](int i) -> bool{
        if(sz(aj[v[i]])==0){ // leaf
            if(mp[{tree.lca(v[i],v[i+1]),v[i+1]}]==0){
                return false;
            }
        }
        else{
            if(mp[{v[i],v[i+1]}]==0){
                return false;
            }
        }

        return true;
    };

    rep(i,0,n){
        if(!check(i)){
            bad.insert(i);
        }
    }


    while(q--){
        int x,y;cin>>x>>y;
        swap(v[x],v[y]);
        
        if(check(x-1)){
            bad.erase(x-1);
        }
        else{
            bad.insert(x-1);
        }
        if(x!=n){
            if(check(x)){
                bad.erase(x);
            }
            else{
                
                bad.insert(x);
            }
        }
        

        if(check(y-1)){
            bad.erase(y-1);
        }
        else{
            
            bad.insert(y-1);
        }
        if(y!=n){
            if(check(y)){
                bad.erase(y);
            }
            else{
                
                bad.insert(y);
            }
        }
        

        if(sz(bad)){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
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