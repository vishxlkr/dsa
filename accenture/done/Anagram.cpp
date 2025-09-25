/*
You are given two strings, s and t . Your task is to determine if it's 
possible to rearrange the characters of s to form the string t . 
Write a function that returns True it's possible to create t by 
rearranging the characters of s and False otherwise. 

Input 
Two strings, s and t where the length of s and t are between 1 and 
1000 characters. 

Output 
Return True if it's possible to create t by rearranging the characters of 
s and False otherwise 

Example: 
s="listen" 
t="silent" 

Output: 
True

*/
#include <iostream>
#include <algorithm> // for sort
#include <string>
using namespace std;

bool checkAnagram(string s, string t) {
    // Convert both strings to lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    transform(t.begin(), t.end(), t.begin(), ::tolower);

    // If lengths differ, they cannot be anagrams
    if (s.length() != t.length()) {
        return false;
    }

    // Sort both strings
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    // Compare
    return s == t;
}

int main() {
    string s, t;

    cout << "Enter first string: ";
    getline(cin, s);

    cout << "Enter second string: ";
    getline(cin, t);

    if (checkAnagram(s, t)) {
        cout << "Output: True" << endl;
    } else {
        cout << "Output: False" << endl;
    }

    return 0;
}
