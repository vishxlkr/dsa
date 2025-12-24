#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int size = (1 << n);
        vector<int> result;
        vector<bool> used(size, false);
        int mask = (1 << n) - 1; // Start with all bits set
        
        // Process bit by bit from highest to lowest
        for (int bit = n - 1; bit >= 0; bit--) {
            vector<int> withBit, withoutBit;
            
            // Separate unused numbers by whether they have current bit
            for (int i = 0; i < size; i++) {
                if (used[i]) continue;
                
                if ((mask & (1 << bit)) && (i & (1 << bit))) {
                    withBit.push_back(i);
                } else if (!(mask & (1 << bit))) {
                    withoutBit.push_back(i);
                }
            }
            
            // If current bit is set in mask and we have numbers with this bit
            if ((mask & (1 << bit)) && !withBit.empty()) {
                // Add all numbers with this bit (in ascending order for lex min)
                sort(withBit.begin(), withBit.end());
                for (int x : withBit) {
                    result.push_back(x);
                    used[x] = true;
                }
                // Bit stays in mask
            } else {
                // Turn off this bit in mask
                mask &= ~(1 << bit);
            }
        }
        
        // Add any remaining numbers
        for (int i = 0; i < size; i++) {
            if (!used[i]) {
                result.push_back(i);
            }
        }
        
        for (int i = 0; i < size; i++) {
            cout << result[i];
            if (i < size - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}