/*

Problem: Write a program in C to display the table of a number and print the sum of all the multiples in it.

Test Cases:

Test Case 1:
Input:
5
Expected Result Value:
5, 10, 15, 20, 25, 30, 35, 40, 45, 50
275

Test Case 2:
Input:
12
Expected Result Value:
12, 24, 36, 48, 60, 72, 84, 96, 108, 120
660

*/


#include <iostream>
using namespace std;

int main() {
    int n, value, sum = 0;

    cout << "Enter the number for which you want to know the table: ";
    cin >> n;

    // Print table values with commas
    for (int i = 1; i <= 10; i++) {
        value = n * i;
        if (i < 10)
            cout << value << ", ";
        else
            cout << value;  // avoid comma at the end
        sum += value;
    }

    cout << "\nSum is " << sum << endl;

    return 0;
}
