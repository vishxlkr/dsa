#include <bits/stdc++.h>
using namespace std;

long getMaxCumulativeObservableSum(vector<int> stockPrice, int k) {
    int n = stockPrice.size();
    unordered_map<int, int> freq;  // to count frequency of elements in window
    long windowSum = 0, maxSum = -1;
    int left = 0;

    for (int right = 0; right < n; right++) {
        int val = stockPrice[right];
        freq[val]++;
        windowSum += val;

        // shrink window if size > k
        if (right - left + 1 > k) {
            freq[stockPrice[left]]--;
            windowSum -= stockPrice[left];
            if (freq[stockPrice[left]] == 0) {
                freq.erase(stockPrice[left]);
            }
            left++;
        }

        // check valid window of size k
        if (right - left + 1 == k) {
            if ((int)freq.size() == k) {  // all distinct
                maxSum = max(maxSum, windowSum);
            }
        }
    }
    return maxSum;
}

int main() {
    // Test Case 1
    vector<int> stock1 = {1, 2, 7, 7, 4, 3, 6};
    cout << getMaxCumulativeObservableSum(stock1, 3) << endl; // 14

    // Test Case 2
    vector<int> stock2 = {1, 2, 3, 7, 3, 5};
    cout << getMaxCumulativeObservableSum(stock2, 3) << endl; // 15

    // Test Case 3
    vector<int> stock3 = {1, 2, 4, 4};
    cout << getMaxCumulativeObservableSum(stock3, 4) << endl; // -1
    vector<int> stock3 = {1, 2, 4, 4};
    cout << getMaxCumulativeObservableSum(stock3, 4) << endl; // -1
}
