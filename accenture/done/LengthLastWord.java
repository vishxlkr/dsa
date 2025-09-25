/*
Problem Statement 

Given a string S consisting of words and spaces, return the lenght of the last word in the string.

Input: "  I am  a passionate   Developer  "
Output: 9

*/

#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int i = s.size() - 1;

    // skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // count length of last word
    int length = 0;
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    cout << "Output: " << lengthOfLastWord(s) << endl;
    return 0;
}
