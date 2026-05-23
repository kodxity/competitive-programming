#include <bits/stdc++.h>
using namespace std;


// ak - yn = c1   b(k-1) - zm = + c2 
// 0 4 3 2 1 0 4 3 2 1 0 4 3 2 1 0 4 3 2 1 0 4 3 2 1 0 4 3 2 1 0 4 3 2 1
// 0 5 3 1 6 4 2 0 5 3 1 6 4 2 0 5 3 1 6 4 2 0 5 3 1 6 4 2 0 5 3 1 6 4 2
void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (gcd(n, a) == 1 && gcd(m, b) == 1 && gcd(max(n, m)%min(n, m), min(n, m)) <= 2) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    



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


