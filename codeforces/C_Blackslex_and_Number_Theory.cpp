#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Find minimum element
        long long minVal = *min_element(a.begin(), a.end());
        
        long long maxK = 0;
        
        // Try each possible target value from minVal down to 0
        for (long long target = minVal; target >= 0; target--) {
            long long g = 0;
            bool allSame = true;
            
            // Calculate GCD of all differences
            for (int i = 0; i < n; i++) {
                if (a[i] != target) {
                    allSame = false;
                    g = gcd(g, a[i] - target);
                }
            }
            
            // If all elements are already equal to target
            if (allSame) {
                // We can use any k, but we want maximum
                // In this case, answer is infinity (or very large)
                // But we continue to find actual maximum from differences
                continue;
            }
            
            maxK = max(maxK, g);
        }
        
        cout << maxK << "\n";
    }
    
    return 0;
}