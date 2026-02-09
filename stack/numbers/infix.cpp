#include<bits/stdc++.h>

using namespace std;

// This function determines the precedence of an operator.
// Higher return value means higher precedence.
int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return 0; // For parentheses or other characters
}

// This function performs a calculation.
int cal(int v1, int v2, char op) {
    if (op == '^') {
        return pow(v1, v2);
    } else if (op == '*') {
        return v1 * v2;
    } else if (op == '/') {
        return v1 / v2;
    } else if (op == '+') {
        return v1 + v2;
    } else if (op == '-') {
        return v1 - v2;
    }
    return 0;
}

// This function evaluates an infix expression.
int evaluate(string str) {
    stack<int> nums;
    stack<char> ops;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (isdigit(ch)) {
            // If the character is a digit, push it to the numbers stack.
            nums.push(ch - '0');
        } else if (ch == '(') {
            // If it's an opening parenthesis, push it to the operators stack.
            ops.push(ch);
        } else if (ch == ')') {
            // If it's a closing parenthesis, evaluate until the opening parenthesis is found.
            while (!ops.empty() && ops.top() != '(') {
                char op = ops.top();
                ops.pop();
                int v2 = nums.top();
                nums.pop();
                int v1 = nums.top();
                nums.pop();
                int v3 = cal(v1, v2, op);
                nums.push(v3);
            }
            if (!ops.empty() && ops.top() == '(') {
                ops.pop(); // Pop the opening parenthesis.
            }
        } else { // Operator
            // While the operator stack is not empty, the top operator is not an opening parenthesis,
            // and the precedence of the top operator is greater than or equal to the current operator,
            // perform the calculation.
            while (!ops.empty() && ops.top() != '(' && precedence(ops.top()) >= precedence(ch)) {
                char op = ops.top();
                ops.pop();
                int v2 = nums.top();
                nums.pop();
                int v1 = nums.top();
                nums.pop();
                int v3 = cal(v1, v2, op);
                nums.push(v3);
            }
            ops.push(ch); // Push the current operator onto the stack.
        }
    }

    // After traversing the complete string, evaluate any remaining operators in the stack.
    while (!ops.empty()) {
        char op = ops.top();
        ops.pop();
        int v2 = nums.top();
        nums.pop();
        int v1 = nums.top();
        nums.pop();
        int v3 = cal(v1, v2, op);
        nums.push(v3);
    }

    return nums.top(); // The final result is the top of the numbers stack.
}

int main() {
    string expression = "3+5*2-8/4";
    cout << "Result of " << expression << " is: " << evaluate(expression) << endl;
    return 0;
}