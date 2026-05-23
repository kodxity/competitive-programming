#include <bits/stdc++.h>
using namespace std;

/*
 * 1 2 3
 * 4 5 6
 * 2 3 4 7 8 9 10 12
 */
void solve() {
    int n;
    cin >> n;
    int a[n][2];
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i][1];
    }

    int lo = 0;
    int hi = 2*n;
    while (lo < hi) {
        int mid = lo + (hi-lo+1)/2;
        int cnt = 0;
        int cnt2 = 0;
        int flag = 1;
        for (int i = 0; i < n; i++) {
            if ((a[i][0] >= mid) + (a[i][1] >= mid) == 2) {
                cnt++;
                flag = 1;
            }
            else if((a[i][0] >= mid) + (a[i][1] >= mid) == 0) {
                if (flag == 1) {
                    flag = 0;
                    cnt2++;
                }
            }
        }
        if (cnt > cnt2) {
            lo = mid;
        }
        else {
            hi = mid-1;
        }
    }
    cout << lo << "\n";





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


