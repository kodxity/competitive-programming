#include <bits/stdc++.h>
using namespace std;

// 0 1 0* 1 0* 1 0* 1

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> b(k);

    int it = 0;

    vector<int> c;
    c.push_back(v[0]);
    int mp[n] = {0};
    for (int i = 0; i < n-1; i++) {
        if (it < k && a[it] == i) {
            b[it] = (int)c.size()-1;
            mp[b[it]] = 1;
            it++;
        }
        if (v[i] != v[i+1]) {
            c.push_back(v[i+1]);
        }
    }
    if (it < k && a[it] == n-1) {
        b[it] = (int)c.size()-1;
        mp[b[it]] = 1;
        it++;
    }
    int tot = 0;
    for (int i = 0; i < (int)c.size(); i++) {
        tot += (c[i] != v[a[0]]);
    }
    int ans = 0;
    int idx = 0;
    int arr[(int)c.size()] = {0};

    int prev = -1;
    while (idx < (int)c.size()) {
        if (mp[idx] == 1) {
            int l = (idx+1)/2;
            int r = tot-l;
            int mn = min(l, r);
                int lit = idx-1;
                for (int i = 0; i < mn; i++) {
                    if (lit > prev) {
                        arr[lit] = 1;
                        lit -= 2;
                    }
                    else {
                        break;
                    }
                }
            int rit = max(prev+2, idx+1);
            int val = min(mn, max(0, (idx + mn*2 - 1 - prev)/2));
            for (int i = 0; i < val; i++) {
                if (rit < (int)c.size()) {
                    arr[rit] = 1;
                    prev = rit;
                    rit += 2;
                }
                else {
                    break;
                }
            }
        }
        idx++;
    }
    for (int i = 0; i < (int)c.size(); i++) {
        if (c[i] != v[a[0]]) {
            if (arr[i]) {
                ans++;
            }
            else {
                ans += 2;
            }
        }
    }
    cout << ans << "\n";



}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


