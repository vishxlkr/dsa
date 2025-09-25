/*
Problem Description :
The Binary number system only uses two digits, 0 and 1 and number system can be called binary string. You are required to implement the following function:

int OperationsBinaryString(char* str);

The function accepts a string str as its argument. The string str consists of binary digits eparated with an alphabet as follows:

– A denotes AND operation
– B denotes OR operation
– C denotes XOR Operation
You are required to calculate the result of the string str, scanning the string to right taking one opearation at a time, and return the same.

Note:

– No order of priorities of operations is required
– Length of str is odd
– If str is NULL or None (in case of Python), return -1

Input:
str: 1C0C1C1A0B1

Output:
1

Explanation:
The alphabets in str when expanded becomes “1 XOR 0 XOR 1 XOR 1 AND 0 OR 1”, result of the expression becomes 1, hence 1 is returned.

Sample Input:
0C1A1B1C1C1B0A0

Output:
0

*/
#include <iostream>
#include <cstring>
using namespace std;

int OperationsBinaryString(char* str) {
    if (str == NULL) return -1;

    int len = strlen(str);
    if (len == 0) return -1;

    int result = str[0] - '0'; // first digit

    for (int i = 1; i < len; i += 2) {
        char op = str[i];       // operator
        int num = str[i + 1] - '0'; // next digit

        if (op == 'A') {
            result = result & num;  // AND
        }
        else if (op == 'B') {
            result = result | num;  // OR
        }
        else if (op == 'C') {
            result = result ^ num;  // XOR
        }
    }

    return result;
}

int main() {
    char str1[] = "1C0C1C1A0B1";
    cout << "Output: " << OperationsBinaryString(str1) << endl;

    char str2[] = "0C1A1B1C1C1B0A0";
    cout << "Output: " << OperationsBinaryString(str2) << endl;

    return 0;
}
