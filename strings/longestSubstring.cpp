#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;
    int left = 0, right = 0, n = s.size();
    int maxLen = 0;

    while (right < n) {
        if (st.find(s[right]) == st.end()) {
            // not in set, expand window
            st.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        } else {
            // duplicate found, shrink from left
            st.erase(s[left]);
            left++;
        }
    }
    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;  // Output: 3
}
