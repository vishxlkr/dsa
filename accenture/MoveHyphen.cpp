/*
Implement the following functions.a

char*MoveHyphen(char str[],int n);

The function accepts a string “str” of length ‘n’, that contains alphabets and hyphens (-). Implement the function to move all hyphens(-) in the string to the front of the given string.

NOTE:- Return null if str is null.

Example :-

Input:
str.Move-Hyphens-to-Front
Output:
—MoveHyphenstoFront
Explanation:-

The string “Move-Hyphens -to-front” has 3 hyphens (-), which are moved to the front of the string, this output is “— MoveHyphen”

Sample Input

Str: String-Compare
Sample Output-

-StringCompare

*/

#include <iostream>
#include <string>
using namespace std;

string moveHyphen(string str) {
    if (str.empty()) {
        return ""; // return empty if string is empty
    }

    string hyphens = "";
    string nonHyphens = "";

    for (char ch : str) {
        if (ch == '-') {
            hyphens += ch;   // collect hyphens
        } else {
            nonHyphens += ch; // collect other chars
        }
    }

    return hyphens + nonHyphens; // put hyphens first
}

int main() {
    string str;
    cout << "Enter string with hyphen: ";
    cin >> str; // note: cin stops at space, so use getline if spaces are needed

    string result = moveHyphen(str);
    cout << "Result: " << result << endl;

    return 0;
}
