/*

You are a given a string str of length n. You have to find the most frequent vowel in the string str
Note: You may assume that str will always hav a unique most frequent vowel.

Sample Test Case:
Input:
7 -> string length
xayuaba

Output:
a

Explanation: As the vowel 'a' occurs the most in the string str, hence 'a' is printed in the output.

*/
#include <bits/stdc++.h>
using namespace std;

char MostFrequentVowel(string str) {
    unordered_map<char, int> vowelCounts;
    char mostFrequentVowel = '\0';
    int maxCount = 0;

    for (char ch : str) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCounts[ch]++;

            // update most frequent vowel
            if (vowelCounts[ch] > maxCount) {
                maxCount = vowelCounts[ch];
                mostFrequentVowel = ch;
            }
        }
    }
    return mostFrequentVowel;
}

int main() {
    int n;
    cout << "Enter length of string: ";
    cin >> n;

    string str;
    cout << "Enter the string: ";
    cin >> str;

    char result = MostFrequentVowel(str);
    cout << "Most Frequent vowel is: " << result << endl;

    return 0;
}
