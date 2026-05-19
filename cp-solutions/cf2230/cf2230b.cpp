#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    // 12, 24, 32, 44
    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '4') {
            ans++;
        }
    }
    int cnt = 0;

    int mode = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != '4') {
            if (s[i] == '2') {
                mode = 0;
            }
            else {
                mode = 1;
            }
            break;
        }
    }

    int omode = mode;
    vector<int> v;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '4') {
            continue;
        }
        if (mode == 0) {
            if (s[i] == '2') {
                cnt++;
            }
            else {
                v.push_back(cnt);
                cnt = 1;
                mode = 1;
            }
        }
        else {
            if (s[i] == '1' || s[i] == '3') {
                cnt++;

            }
            else {
                v.push_back(cnt);
                cnt = 1;
                mode = 0;
            }
        }
    }
    v.push_back(cnt);

    int fans = 1e9;
    int sum = 0;
    mode = omode;
    if (mode == 0) {
        for (int i = 0; i < (int)v.size(); i+=2) {
            sum += v[i];
        }
    }
    else {
        for (int i = 1; i < (int)v.size(); i+=2) {
            sum += v[i];
        }
    }

    int sum1 = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if (mode == 0) {

            if (i%2 == 0) {
                sum -= v[i];
                fans = min(fans, ans+sum+sum1);
            }
            else {
                fans = min(fans, ans+sum+sum1);
                sum1 += v[i];
            }

        }
        else {
            if (i%2 == 0) {
                fans = min(fans, ans+sum+sum1);
                sum1 += v[i];

            }
            else {
                sum -= v[i];
                fans = min(fans, ans+sum+sum1);
            }
        }

    }

    cout << fans << "\n";
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

