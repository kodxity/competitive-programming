#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> k;
    k--;
    int l = 1e9;
    int r = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] != v[k]) {
            l = min(l, i);
            r = i;
        }
    }

    int cnt = 0;
    for (int i = k; i < r; i++) {
        if (v[i] != v[i+1]) {
            cnt++;
        }
    }

    int cnt2 = 0;
    for (int i = k; i > l; i--) {
        if (v[i] != v[i-1]) {
            cnt2++;
        }
    }

    if (l == 1e9 && r == -1) {
        cout << 0 << "\n";
        return;
    }
    cout << max(cnt, cnt2) + 1 << "\n";


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


