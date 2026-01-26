#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
    int n = arr.size();
    int lo = 0;
    int hi = n - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] > arr[hi]) {
            lo = mid + 1;
        } else if (arr[mid] < arr[hi]) {
            hi = mid;
        } else {
            hi--;  // arr[mid] == arr[hi]
        }
    }

    return arr[lo];
}

int main() {
    // Example input
    vector<int> arr = {2, 2, 2, 0, 1, 2};

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    int result = findMin(arr);
    cout << "Minimum element in rotated array: " << result << endl;

    return 0;
}


