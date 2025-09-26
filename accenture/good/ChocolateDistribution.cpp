/*
Given an array of N integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 

Each student gets one packet.
The difference between the number of chocolates in the packet with maximum chocolates and the packet with minimum chocolates given to the students is minimum.
Examples:

Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3 
Output: Minimum Difference is 2 
Explanation:
We have seven packets of chocolates and we need to pick three packets for 3 students 
If we pick 2, 3 and 4, we get the minimum difference between maximum and minimum packet sizes.

Input : arr[] = {3, 4, 1, 9, 56, 7, 9, 12} , m = 5 
Output: Minimum Difference is 6 

Input : arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50} , m = 7 
Output: Minimum Difference is 10 

*/

#include <bits/stdc++.h>
using namespace std;

int chocolateDistribution(vector<int>& arr, int m) {
    int n = arr.size();
    
    // Edge cases
    if (n == 0 || m == 0) return 0;
    if (m > n) return -1;

    sort(arr.begin(), arr.end());

    int minDiff = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        minDiff = min(minDiff, diff);
    }

    return minDiff;
}

int main() {
    vector<int> arr = {12, 4, 7, 9, 2, 23, 25, 41,
                       30, 40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7;

    int result = chocolateDistribution(arr, m);

    if (result != -1)
        cout << "Minimum difference is " << result << endl;
    else
        cout << "Invalid input" << endl;

    return 0;
}
