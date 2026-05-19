#include <bits/stdc++.h>
using namespace std;

vector<int> aj[400005];
int vis[400005] = {0};
int pre[400005] = {0};
map<pair<int,int>, int> mp;
int team[400005] = {0};
int color = 0;
int sz = 0;

void dfs(int n, int p) {
	vis[n] = 1;
	for (auto x : aj[n]) {
		if (x != p) {
			if (vis[x] == 0) {
				dfs(x, n);
				pre[n] += pre[x];
				if (!mp[{x, n}]) {
					mp[{x, n}] = n;
					mp[{n, x}] = n;
				}
			}
			else if (vis[x] == 1) {
				pre[n]++;
				if (!mp[{x, n}]) {
					mp[{x, n}] = n;
					mp[{n, x}] = n;
				}
			}
			else {
				pre[n]--;
			}
		}
	}

	// bridge
	if (pre[n] == 0) {
		mp[{n,p}] = -1;
		mp[{p,n}] = -1;
	}
	vis[n] = 2;
}

void dfs2(int n, int p) {
	vis[n] = 1;
	team[n] = color;
	sz++;
	for (auto x : aj[n]) {
		if (x != p) {
			if (!vis[x] && mp[{x,n}] != -1) {
				dfs2(x, n);
			}
		}

	}


}

vector<pair<int,int>> e;
vector<pair<int,int>> aj2[400005];
void dfs3(int n, int p) {

	vis[n] = 1;
	for (auto [x, i] : aj2[n]) {
		if (x != p) {
			if (!vis[x]) {
				auto [a, b] = e[i];
				if (team[a] == x) {
					mp[{a,b}] = a;
					mp[{b,a}] = a;
				}
				else {
					mp[{a,b}] = b;
					mp[{b,a}] = b;
				}
				dfs3(x, n);
			}
		}

	}
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
		cin >> x >> y;
		aj[x].push_back(y);
		aj[y].push_back(x);
		e.push_back({x,y});
    }

	dfs(1, 0);
	for (int i = 0; i <= n; i++) {
		vis[i] = 0;
	}

	
	int ans = 0;
	
	int bcolor = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			sz = 0;
			dfs2(i, 0);
			if (sz > ans) {
				ans = sz;
				bcolor = color;
			}
			color++;
		}
	}

	for (int i = 0; i < color; i++) {
		vis[i] = 0;
	}

	cout << ans << "\n";
	for (int i = 0; i < (int)e.size(); i++) {
		auto [x, y] = e[i];
		if (mp[{x, y}] == -1) {
			aj2[team[x]].push_back({team[y], i});
			aj2[team[y]].push_back({team[x], i});
		}
	}

	dfs3(bcolor, -1);

	
	for (auto [x, y] : e) {
		if (mp[{x,y}] == x) {
			cout << x << " " << y << "\n";
		}
		else {
			cout << y << " " << x << "\n";
		}
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

