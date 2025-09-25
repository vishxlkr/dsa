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
#include <sstream>   // include this for stringstream
using namespace std;

int main() {
    string s = "I am learning C++";
    stringstream ss(s);  // put the string into stringstream
    string word;

    while (ss >> word) {   // this extracts one word at a time (like cin >> word)
        cout << word << endl;
    }

    return 0;
}
