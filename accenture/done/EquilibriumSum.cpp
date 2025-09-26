/*
Problem Statement :

Given the function accepts an integer arr of size n as its argument. The function needs to return the index of equiibrium point int ht array, where the sum of elements on the left of the index is equal to the sum of elements on the right of the index. If no equilibrium point exists, the function should return -1.

Input arr: {3,4,3,1,6}
Output: 2   

Explanation: 3+4 = 7 and 1+6 = 7 so 3 is the equilibrium point having index 2.

*/

#include <iostream>
#include <vector>
using namespace std;

int equilibrium(vector<int>& arr) {
    int n = arr.size();
    int total = 0, leftsum = 0;

    // Step 1: calculate total sum
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }

    // Step 2: traverse to check equilibrium
    for (int i = 0; i < n; i++) {
        int rightsum = total - arr[i] - leftsum;

        if (leftsum == rightsum) {
            return i; // found equilibrium index
        }
        leftsum += arr[i];
    }

    return -1; // no equilibrium index found
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

    int ans = equilibrium(arr);
    if (ans != -1)
        cout << "Equilibrium index is: " << ans << endl;
    else
        cout << "No Equilibrium index exists." << endl;

    return 0;
}
