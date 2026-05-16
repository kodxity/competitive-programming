#include <bits/stdc++.h>
using namespace std;

void solve () {
	long long a, n;
	cin >> a >> n;
	long long x, y;
	cin >> x >> y;
	long long ans = min(abs(a-(10*x+y)), abs(a-(10*y+x)));
	ans = min(ans, abs(a-(10*x+x)));
	ans = min(ans, abs(a-(10*y+y)));
	ans = min(ans, abs(a-x));
	ans = min(ans, abs(a-y));
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

