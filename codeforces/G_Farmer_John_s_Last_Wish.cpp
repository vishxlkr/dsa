#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        ll total = 0;
        ll min_odd = LLONG_MAX;
        int odd_count = 0;
        for (int i = 0; i < n; ++i) {
            ll v; cin >> v;
            total += v;
            if (v % 2 != 0) {
                ++odd_count;
                min_odd = min(min_odd, v);
            }
        }
        if (odd_count == 0) {
            cout << 0 << '\n';
        } else if (odd_count % 2 == 1) {
            cout << total << '\n';
        } else {
            cout << (total - min_odd) << '\n';
        }
    }
    return 0;
}
