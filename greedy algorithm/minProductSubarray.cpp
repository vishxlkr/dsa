#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minProduct(vector<int>& arr) {
    int cn = 0, cz = 0, cp = 0;
    long long prod_pos = 1;
    long long prod_neg = 1;
    int largestNegative = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0) {
            cn++;
            prod_neg *= arr[i];
            largestNegative = max(largestNegative, arr[i]);
        } else if (arr[i] == 0) {
            cz++;
        } else {
            cp++;
            prod_pos *= arr[i];
        }
    }

    if (cn == 0) {
        if (cz > 0) {
            return 0;
        } else {
            auto it = min_element(arr.begin(), arr.end());
            return *it;
        }
    } else {
        if (cn % 2 == 0) {
            // Even number of negatives
            // To get minimum product, we want a negative result
            // Remove the largest negative to make the product negative
            return (prod_neg / largestNegative) * prod_pos;
        } else {
            // Odd number of negatives
            // Product is already negative, which is the minimum
            // (unless there are zeros)
            if (cz > 0) {
                return 0;
            } else {
                return prod_neg * prod_pos;
            }
        }
    }
}

int main() {
    vector<int> arr = {-2, -3, 1, 4, -2};
    cout << minProduct(arr) << endl;
    return 0;
}