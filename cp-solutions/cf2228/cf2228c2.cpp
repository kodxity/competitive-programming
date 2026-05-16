#include <bits/stdc++.h>
using namespace std;

void solve () {
	long long x, n;
	cin >> x >> n;
	long long px = x;
	vector<long long> v(n);
	int has[10] = {0};
	long long mn = 10;
	long long mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		has[v[i]] = 1;
		mn = min(mn, v[i]);
		mx = max(mx, v[i]);
	}
	vector<long long> a;
	while (x) {
		a.push_back(x%10);
		x /= 10;
	}
	x = px;
	if ((int)a.size() == 0) {

		cout << mn << "\n";
		return;
	}

	reverse(a.begin(), a.end());

	long long ans = 1e18;

	int idx = -1;
	for (int i = 0; i < (int)a.size(); i++) {
		if (!has[a[i]]) {
			idx = i;
			break;
		}
	}
	if (idx == -1) {
		cout << 0 << "\n";
		return;
	}
	int mxidx = idx;

	for (int j = 0; j <= mxidx; j++) {
		idx = j;
		long long val = 0;
		for (int i = idx; i < (int)a.size(); i++) {
			val *= 10;
			val += a[i];
		}
		sort(v.begin(), v.end());
		
		int sz = (int)a.size() - idx-1;
		long long val1 = -1;
		long long val2 = -1;
		int mode = 1;
		for (int i = 0; i < (int)v.size(); i++) {
			if (v[i] < a[idx]) {
				val1 = v[i];
			}
		}
		for (int i = (int)v.size() - 1; i >= 0; i--) {
			if (v[i] > a[idx]) {
				val2 = v[i];
			}
		}

		if (val1 == -1) {
			mode = 0;
		}
		else if (val2 == -1) {
			mode = 2;
		}
		while (sz--) {
			val1 *= 10;
			val1 += mx;
			val2 *= 10;
			val2 += mn;
		}
		if (mode == 0) {
			ans = min(ans, abs(val-val2));
		}
		else if (mode == 1) {
			ans = min(ans, min(abs(val-val1), abs(val-val2)));
		}
		else {
			ans = min(ans, abs(val-val1));
		}
	}
	long long cnt1 = 0;
	if ((int)a.size() > 1) {
		for (int i = 0; i < (int)a.size()-1; i++) {
			cnt1 *= 10;
			cnt1 += mx;
		}
		ans = min(ans, abs(x-cnt1));
		cnt1 = 0;
	}
	
	long long cnt2 = 0;
	for (int i = 1; i < 10; i++) {
		if (has[i]) {
			cnt2 = i;
			break;
		}
	}

	if (cnt2 != 0) {
		for (int i = 0; i < (int)a.size(); i++) {
			cnt2 *= 10;
			cnt2 += mn;
		}
		ans = min(ans, abs(x-cnt2));
	}
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

