#include <bits/stdc++.h>
using namespace std;

void countsort(vector<int> &v) {
    int n = v.size();
    if (n == 0) return; // Handle empty array case

    int max = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        if (max < v[i]) max = v[i];
    }

    vector<int> freq(max + 1, 0); // Fix: Properly initialize with size (max + 1)

    for (int i = 0; i < n; i++) {
        freq[v[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        freq[i] += freq[i - 1];
    }

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        ans[--freq[v[i]]] = v[i];
    }

    for (int i = 0; i < n; i++) {
        v[i] = ans[i];
    }
}

int main() {
    vector<int> v = {5, 3, 9, 3, 2, 4, 8, 7};

    countsort(v);

    for (auto ele : v) {
        cout << ele << " ";
    }

    return 0;
}
