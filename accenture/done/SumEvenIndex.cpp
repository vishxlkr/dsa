/*
Problem Statement 

Given an array A of length N, find the sum of even positions after reversing the array. Your task is to find and return an integer value represneting sum of the array elements present at the even index of the reveresed array.

input: N = 6, arr = 10,20,30,40,50,60
output: 120

Explanation: reversed array: 60,50,40,30,20,10 and then sum even index(index starting from 0) elements which are 60,40,20

*/

#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

int sumEvenIndex(vector<int>& arr, int n) {
    if (n == 0) return 0;

    // Step 1: Reverse the array
    reverse(arr.begin(), arr.end());

    // Step 2: Sum elements at even indices
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { // even index
            sum += arr[i];
        }
    }

    return sum;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Output: " << sumEvenIndex(arr, n) << endl;
    return 0;
}
