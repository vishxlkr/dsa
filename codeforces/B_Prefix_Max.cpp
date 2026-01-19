#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

// Helper function to calculate prefix max sum
ll calculate_value(const vector<int>& arr) {
    ll total = 0;
    int current_max = 0;
    for (int x : arr) {
        current_max = max(current_max, x);
        total += current_max;
    }
    return total;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Initial value (for the "at most one swap" condition)
    ll max_ans = calculate_value(a);

    // Brute force all possible swaps
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(a[i], a[j]);
            max_ans = max(max_ans, calculate_value(a));
            swap(a[i], a[j]); // Swap back to restore original array
        }
    }

    cout << max_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}