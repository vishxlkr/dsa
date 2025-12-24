#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin>>n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        ll base = 0;
        for (int i = 0; i + 1 < n; ++i)
            base += llabs(a[i] - a[i + 1]);

        ll ans = (ll)4e18;

        // remove first
        ans = min(ans, base - llabs(a[0] - a[1]));
        // remove last
        ans = min(ans, base - llabs(a[n - 2] - a[n - 1]));

        // remove middle elements
        for (int k = 1; k + 1 < n; ++k) {
            ll removeCost = llabs(a[k - 1] - a[k]) + llabs(a[k] - a[k + 1]);
            ll addCost = llabs(a[k - 1] - a[k + 1]);
            ll cur = base - removeCost + addCost;
            ans = min(ans, cur);
        }

        cout << ans << "\n";
    }
    return 0;
}
