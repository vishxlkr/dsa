#include <iostream>
#include <string>
using namespace std;

string reverseString(string str) {
    string reversed = "";
    for (int i = 0; i < str.length(); i++) {
        reversed = str[i] + reversed;  // add current char at front
    }
    return reversed;
}

int main() {
    string str = "hello";
    cout << reverseString(str) << endl;
    return 0;
}
