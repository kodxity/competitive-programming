#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> ans;
    int cnt[n] = {0};
    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            if (i > 0) {
                cnt[i-1]++;
            }
            cnt[i]++;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (cnt[i]%2 == 1) {
            ans.push_back(i);
        }
    }
    cout << (int)ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i]+1 << " ";
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


