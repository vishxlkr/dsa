#include <iostream>
#include <climits> // for INT_MIN
using namespace std;

int secondLargest(int arr[], int n) {
    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    return second;
}

int main() {
    int arr[] = {1, 3, 5, 2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = secondLargest(arr, n);

    cout << "Second Largest: " << result << endl;
    return 0;
}
