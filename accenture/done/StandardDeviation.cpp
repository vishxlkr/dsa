#include <iostream>
#include <vector>
#include <cmath>  // for sqrt() and pow()
using namespace std;

// Function to calculate Standard Deviation
double standardDeviation(vector<int> arr) {
    int n = arr.size();
    double sum = 0.0, mean, variance = 0.0;

    // Step 1: Calculate mean
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    mean = sum / n;

    // Step 2: Calculate variance (average of squared differences)
    for (int i = 0; i < n; i++) {
        variance += pow(arr[i] - mean, 2);
    }
    variance = variance / n;  // population SD (if sample use n-1)

    // Step 3: Standard Deviation = sqrt(variance)
    return sqrt(variance);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double result = standardDeviation(arr);
    cout << "Standard Deviation = " << result << endl;

    return 0;
}
