/*
Problem Statement 

You are required to input the size of the matrix then the elements of matrix, then you have to divide the main matrix in two sub matrices (even and odd) in such a way that element at 0 index will be considered as even and element at 1st index will be considered as odd and so on. then you have sort the even and odd matrices in ascending order then print the sum of second largest number from both the matrices

Example

enter the size of array : 5
enter element at 0 index : 3
enter element at 1 index : 4
enter element at 2 index : 1
enter element at 3 index : 7
enter element at 4 index : 9
Sorted even array : 1 3 9
Sorted odd array : 4 7

7

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void divideArray(const vector<int>& main, vector<int>& even, vector<int>& odd) {
    for (int i = 0; i < main.size(); i++) {
        if (i % 2 == 0) {
            even.push_back(main[i]);
        } else {
            odd.push_back(main[i]);
        }
    }
}

int secondLargest(const vector<int>& list) {
    if (list.size() < 2) {
        throw runtime_error("List must have at least two elements to find the second largest");
    }
    return list[list.size() - 2]; // since sorted ascending
}

int sumOfSecondLargestElements(vector<int>& even, vector<int>& odd) {
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    cout << "Sorted even array: ";
    for (int e : even) cout << e << " ";
    cout << endl;

    cout << "Sorted odd array: ";
    for (int e : odd) cout << e << " ";
    cout << endl;

    int evenSec = secondLargest(even);
    int oddSec = secondLargest(odd);

    cout << "Second Largest in Even List: " << evenSec << endl;
    cout << "Second Largest in Odd List: " << oddSec << endl;

    return evenSec + oddSec;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> main(n), even, odd;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> main[i];
    }

    divideArray(main, even, odd);

    try {
        int sum = sumOfSecondLargestElements(even, odd);
        cout << "Sum of Second Largest Elements: " << sum << endl;
    } catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
