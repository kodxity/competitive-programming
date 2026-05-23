#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    __gnu_pbds::gp_hash_table<long long, int, custom_hash> mp;
    __gnu_pbds::gp_hash_table<long long, int, custom_hash> cnt;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        cnt[v[i]]++;
        int move = 0;
        if (cnt[v[i]] == n) {
            ans = min(ans, mp[v[i]]);
        }
        if (v[i] == 1) {
            cnt[2]++;
            mp[2]++;
            if (cnt[2] == n) {
                ans = min(ans, mp[2]);
            }
        }
        while (v[i] != 1) {
            if (v[i]%2 == 0) {
                v[i] /= 2;
            }
            else {
                v[i]++;
            }
            move++;
            mp[v[i]] += move;
            cnt[v[i]]++;
            if (cnt[v[i]] == n) {
                ans = min(ans, mp[v[i]]);
            }
        }
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


