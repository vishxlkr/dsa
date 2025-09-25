/*

Problem Statement 

You are provided with a string which has a sequence of 1s and Os. This sequence is the encoded version of a english word. You are supposed to write a program to decode the provided string and find the original word. Each uppercase Alphabet is representing by a sequence of 1s

Input: 10110111
Output: ABC

Explanation: 1 0 1 1 0 1 1 1
             A    B      C



*/

#include <iostream>
#include <string>
using namespace std;

string Decoder(string s) {
    if (s.empty() || s[0] == '0') {
        return ""; // invalid input
    }

    string ans = "";
    int count = 0;

    for (char ch : s) {
        if (ch == '1') {
            count++;
        } else { // ch == '0'
            ans += char('A' + count - 1);
            count = 0;
        }
    }

    // handle the last group of 1s
    if (count > 0) {
        ans += char('A' + count - 1);
    }

    return ans;
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    cout << "Output: " << Decoder(str) << endl;

    return 0;


}
