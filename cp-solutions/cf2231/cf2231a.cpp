#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << n+i << " ";
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


