#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> a(n);
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    
    long long pre = 0;

    int prev = -1;
    int last = -1;
    for (int i = 0; i < n; i++) {
        pre += a[i];
        if (s[i] == '0') {
            last = i;
            a[i] = max(0LL, c[i]-pre);
            pre += a[i];
        }
        if (c[i] < pre) {
            if (last != -1 && last >= prev) {
                a[last] -= pre-c[i];
                pre = c[i];
            }
            else {
                cout << "No\n";
                return;
            }
        }
        if (i > 0 && c[i] != c[i-1]) {
            prev = i;
        }
    }

    pre = 0;
    long long mx = -1e18;
    for (int i = 0; i < n; i++) {
        pre += a[i];
        mx = max(mx, pre);
        if (mx != c[i]) {
            cout << "No\n";
            return;
        }
    }

    
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
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


