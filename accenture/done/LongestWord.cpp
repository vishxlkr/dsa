/*

Rohan is a kid who has just learned about creating words from 
alphabets. He has written some words in the notepad of his Father 
laptop. Now his father wants to find the longest word written by Rohan 
using a computer program. Write a program to find the longest string 
in a given list of strings. 

Example: 
Input: yes no number 
Output: The longest string is: number

*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string longestWord(string s) {
    stringstream ss(s);   // split string by spaces
    string word;
    string longest = "";
    int maxLen = 0;

    while (ss >> word) {  // extracts each word
        if (word.length() > maxLen) {
            maxLen = word.length();
            longest = word;
        }
    }

    return longest;
}

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    cout << "The longest string is: " << longestWord(s) << endl;
    return 0;
}
