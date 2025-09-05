#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int common;
        if (a[0] == a[1] || a[0] == a[2]) 
            common = a[0];
        else 
            common = a[1];

        for (int i = 0; i < n; i++) {
            if (a[i] != common) {
                cout << i + 1 << "\n"; // 1-based index
                break;
            }
        }
    }
    return 0;
}
