#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

int min_operations(int n, const vector<int>& arr) {
   
    unordered_map<int, int> freq;
    
    
    for (int num : arr) {
        for (int div = 1; div <= num; ++div) {
            if (num % div == 0) {
                freq[div]++;
            }
        }
    }
    
    
    int max_freq = 0;
    for (const auto& entry : freq) {
        max_freq = max(max_freq, entry.second);
    }

    return n - max_freq;
}

int main() {
    int t; 
    cin >> t;
    
    // Process each test case
    while (t--) {
        int n; // length of the array
        cin >> n;
        
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        
        cout << min_operations(n, arr) << endl;
    }
    
    return 0;
}
