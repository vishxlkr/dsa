/*
Question: Write a program in C such that it takes a lower limit and upper limit as inputs and print all the intermediate palindrome numbers.

Test Cases:

TestCase 1:
Input :
10 , 80
Expected Result:
11 , 22 , 33 , 44 , 55 , 66 , 77.

Test Case 2:
Input:
100,200
Expected Result:
101 , 111 , 121 , 131 , 141 , 151 , 161 , 171 , 181 , 191.

*/

#include <iostream>
using namespace std;

// Function to check if a number is palindrome
bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;

    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    int lower, upper;
    cout << "Enter lower limit: ";
    cin >> lower;
    cout << "Enter upper limit: ";
    cin >> upper;

    cout << "Palindrome numbers between " << lower << " and " << upper << ":\n";
    for (int i = lower; i <= upper; i++) {
        if (isPalindrome(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
