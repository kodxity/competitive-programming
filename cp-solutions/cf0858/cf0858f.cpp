#include <bits/stdc++.h>
using namespace std;

vector <int> aj[200005];
int vis[200005];
int marked[200005];
map<int,int> edge;
vector<tuple<int,int,int>> ans;

void dfs(int n, int p) {
	vis[n] = 1;
	vector<int> v;
	for (auto x : aj[n]) {
		if (x != p) {
			if (vis[x] == 0) {
				dfs(x, n);
				if (!marked[x]) {
					v.push_back(x);
				}
			}
			else if (vis[x] == 1) {
				v.push_back(x);
			}
		}
	}
	for (int i = 0; i+1 < (int)v.size(); i+=2) {
		ans.push_back({v[i], n, v[i+1]});
	}
	if (p != -1 && (int)v.size()%2 == 1) {
		marked[n] = 1;
		ans.push_back({v.back(), n, p});
	}
	else {
		marked[n] = 0;
	}

	
	vis[n] = 2;

}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; 
		b--;
		aj[a].push_back(b);
		aj[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (vis[i] == 0) {
			dfs(i,-1); 
		}
	}
	cout << (int)ans.size() << "\n";
	for (auto [a, b, c] : ans) {
		cout << a+1 << " " << b+1 << " " << c+1 << "\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}

