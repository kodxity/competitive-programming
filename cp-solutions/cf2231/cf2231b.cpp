#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int mx = 0;
    for (int i = 0; i < n-1; i++) {
        mx = max(mx, v[i]-v[i+1]);

    }
    if (mx <= 0) {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i-1]) {
            v[i] += mx;
        }
    }

    for (int i = 0; i < n-1; i++) {
        if (v[i] > v[i+1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

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


