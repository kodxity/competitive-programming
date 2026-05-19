#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;
    if (3*a < b) {
        cout << n * a << "\n";
        return;
    }

    cout << n/3 * b + min((n%3)*a, b) << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}

