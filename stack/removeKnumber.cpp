#include <bits/stdc++.h>
using namespace std;

string maxAfterRemovingK(string num, int k) {
    int n = num.size();
    if (k >= n) return "0";  // Remove all digits
    vector<char> st;         // stack implemented as vector

    for (char digit : num) {
        // Pop smaller digits if we can remove more
        while (k > 0 && !st.empty() && st.back() < digit) {
            st.pop_back();
            k--;
        }
        st.push_back(digit);
    }

    // If still need to remove digits, remove from end
    while (k > 0 && !st.empty()) {
        st.pop_back();
        k--;
    }

    // Build result string
    string result(st.begin(), st.end());
    // Strip leading zeros if needed
    int pos = 0;
    while (pos + 1 < result.size() && result[pos] == '0') pos++;
    return result.substr(pos);
}

//question
//Remove exactly k digits from N's decimal representation—without changing the relative order of the remaining digits—to form the largest possible number.

int main() {
    string num = "1729";
    int k = 2;
    cout << maxAfterRemovingK(num, k) << endl;  // Outputs: 79
    return 0;
}
