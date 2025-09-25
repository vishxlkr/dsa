/*

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

*/
#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotate(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;  // normalize k

    // Step 1: reverse whole array
    reverse(arr, 0, n - 1);

    // Step 2: reverse first k elements
    reverse(arr, 0, k - 1);

    // Step 3: reverse remaining n-k elements
    reverse(arr, k, n - 1);
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    rotate(arr, k);

    cout << "Array after rotating by " << k << " steps: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
