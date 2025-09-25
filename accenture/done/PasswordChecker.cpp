/*
You are given a function.
int CheckPassword(char str[], int n);
The function accepts string str of size n as an argument. Implement the function which returns 1 if given string str is valid password else 0.
str is a valid password if it satisfies the below conditions.

– At least 4 characters
– At least one numeric digit
– At Least one Capital Letter
– Must not have space or slash (/)
– Starting character must not be a number

Assumption:
Input string will not be empty.

Example:

Input 1:
aA1_67
Input 2:
a987 abC012

Output 1:
1
Output 2:
0

*/

#include <iostream>
#include <cstring>
using namespace std;

int CheckPassword(char str[], int n) {
    if (n < 4) return 0;

    // First char must not be digit
    if (str[0] >= '0' && str[0] <= '9') return 0;

    bool hasDigit = false, hasUpper = false;

    for (int i = 0; i < n; i++) {
        if (str[i] == ' ' || str[i] == '/') {
            return 0;  // invalid character
        }
        if (str[i] >= '0' && str[i] <= '9') {
            hasDigit = true;
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            hasUpper = true;
        }
    }

    return (hasDigit && hasUpper) ? 1 : 0;
}

int main() {
    char str[100];
    cout << "Enter password: ";
    cin.getline(str, 100);

    int n = strlen(str);
    cout << CheckPassword(str, n) << endl;

    return 0;
}
