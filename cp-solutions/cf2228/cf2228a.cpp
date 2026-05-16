#include <bits/stdc++.h>
using namespace std;

void solve () {
	int n;
	cin >> n;
	vector <int> v(n);
	int cnt[3] = {0};
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		cnt[v[i]]++;
	}
	int ans = min(cnt[1], cnt[2]);
	ans += (max(cnt[1],cnt[2]) - ans)/3; 
	ans += cnt[0];
	cout << ans << "\n";
}

int main () {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}

