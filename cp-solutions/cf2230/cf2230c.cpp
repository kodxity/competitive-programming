#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    long long cnt = 0;
    long long ans = 0;
    long long good = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        if (v[i] == 1) {
            cnt++;
        }
        else {
            ans += v[i];
            good += (v[i]-2)/2;
        }
    }

    if (sum < 3 || cnt == n) {
        cout << 0 << "\n";
        return;
    }
    
    if (cnt == n-1) {
        good++;
    }
    cout << min(cnt, good) + ans << "\n";
    

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

