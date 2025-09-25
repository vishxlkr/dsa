/*
Problem Statement 

A number whose sum of digits is prime. 

Input: 43
Output: YES (4+3 = 7)

Input: 123
Output: NO (1+2+3 = 6)

*/

#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to check if sum of digits is prime
string googlyPrime(int n) {
    int sum = 0;
    while (n > 0) {
        int lastDigit = n % 10;
        sum += lastDigit;
        n /= 10;
    }

    if (isPrime(sum)) return "YES";
    else return "NO";
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Output: " << googlyPrime(n) << endl;
    return 0;
}
