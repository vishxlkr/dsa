
/*
Problem Statement :

Write a function that takes an integer n as input and returns the sum of all prime numbers less than N.

Input: 10
Output: 17

Explanation: prime no less than 10 are: 2, 3, 5, 7 

*/


#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int j = 2; j <= sqrt(num); j++) {
        if (num % j == 0) return false;
    }
    return true;
}

int sumPrime(int n) {
    int sum = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    cout << "Output: " << sumPrime(n) << endl;

    return 0;
}
