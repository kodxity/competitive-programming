#include <bits/stdc++.h>
using namespace std;

void solve () {
	int n, x1, x2, k;
	cin >> n >> x1 >> x2 >> k;
	if (n == 2 || n == 3) {
		cout << 1 << "\n";
		return;
	}
	int m = min(abs(x1 - x2), n - abs(x1 - x2));
	int ans = 0;
	if (abs(x1 - x2) == n - abs(x1 - x2)) {
		ans++;
		m--;
	}
	if (m == 0) {
		cout << ans << "\n";
		return;
	}
	ans += k;
	ans += m;
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

