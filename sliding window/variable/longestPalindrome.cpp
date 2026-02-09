// You are given a string s.
// You need to find the longest substring of s that is a palindrome (reads the same forward and backward).

// 🧠 Example:

// Input:
// s = "babad"

// Output:
// "bab" (or "aba", both are correct)




#include <bits/stdc++.h>
using namespace std;

string expandFromCenter(string s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    // when loop breaks, we went one step extra on both sides
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    
    string longest = "";
    for (int i = 0; i < s.size(); i++) {
        // odd length palindrome
        string odd = expandFromCenter(s, i, i);
        // even length palindrome
        string even = expandFromCenter(s, i, i + 1);

        // pick the longer one between odd and even
        string curr = (odd.size() > even.size()) ? odd : even;

        if (curr.size() > longest.size())
            longest = curr;
    }
    return longest;
}

int main() {
    string s = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s);
    return 0;
}


