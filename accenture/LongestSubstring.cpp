/*

Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.


*/

#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s) {
    unordered_set<char> set;
    int maxLength = 0;
    int start = 0, end = 0;

    while (start < s.size()) {
        if (set.find(s[start]) == set.end()) {
            set.insert(s[start]);
            maxLength = max(maxLength, start - end + 1);
            start++;
        } else {
            set.erase(s[end]);
            end++;
        }
    }
    return maxLength;
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    cout << "Output: " << longestSubstring(str) << endl;
    return 0;
}
