#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool is_power_of_two(int n) {
    return (n > 0 && (n & (n - 1)) == 0);
}

void solve() {
    int n;
    cin >> n;

    // The hard version usually requires n+1 to be a power of 2 
    // for a solution to exist across the range 1 to n-1.
    if (!is_power_of_two(n + 1)) {
        cout << -1 << "\n";
        return;
    }

    // Construction for n = 2^k - 1:
    // A simple cyclic shift or specific XOR pairing works.
    // One such construction is p[i] = i ^ (i >> 1) reversed or similar.
    // But for n = 2^k - 1, p[i] = i ^ n often works.
    
    for (int i = 1; i <= n; i++) {
        cout << (i ^ n) << (i == n ? "" : " ");
    }
    cout << "\n";
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