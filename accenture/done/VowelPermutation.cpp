/*
Problem Statement 

You are given a string S and your task is to find and return the count of permutation formed by fixing the positions of the vowels present in the string.

Input: ABC
Output: 2

Explanation: A will be constant, and remaining 2 will return their permutation which is factorial of 2

*/

#include <bits/stdc++.h>
using namespace std;

long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
    }
    return ans;
}

long long permutation(const string &s) {
    unordered_set<char> vowels = 
        {'A','E','I','O','U','a','e','i','o','u'};
    
    int nonVowelCount = 0;
    for (char ch : s) {
        if (vowels.find(ch) == vowels.end()) {
            nonVowelCount++;
        }
    }
    return factorial(nonVowelCount);
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Output: " << permutation(s) << endl;
    return 0;
}
