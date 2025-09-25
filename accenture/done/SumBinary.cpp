// # You are given an i nt eger 'n'. Write a cpp code function to calculate and return the sum of the digits in 'n' after converting it to its binary representation.

// # For  example, 15,  which has a  binary representation of  1111,  should 
// # ret urn 4.





#include <iostream>
using namespace std;

// Function to calculate sum of binary digits without bitwise operators
int SumBinary(int n) {
    int sum = 0;

    while (n > 0) {
        int remainder = n % 2;   // Get last binary digit (0 or 1)
        sum += remainder;        // Add it to sum
        n = n / 2;               // Remove last binary digit
    }

    return sum;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    int result = SumBinary(n);
    cout << "Sum of binary digits: " << result << endl;

    return 0;
}
