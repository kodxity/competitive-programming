#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    vector<long long> a;
    for (int i = 0; i < n; i++) {
        int u; 
        cin >> u;
        a.push_back(u);
    }

    vector<long long> b;
    for (int i = 0; i < n; i++) {
        int u; 
        cin >> u;
        b.push_back(u);
    }
    vector<long long> v(n);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, min(a[i], b[i]));
        v[i] = max(a[i], b[i]);
    }
    for (int i = 0; i < n; i++) {
        ans += v[i];
    }
    cout << ans << "\n";
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


