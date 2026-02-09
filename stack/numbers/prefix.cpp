#include<bits/stdc++.h>

using namespace std;

// This function performs a calculation based on the given operator.
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
    return 0; // Return 0 for an unknown operator.
}

// This function evaluates a postfix expression.
int evaluate(string str) {
    stack<int> st;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (isdigit(ch)) {
            // Convert the character digit to an integer and push it onto the stack.
            st.push(ch - '0');
        } else {
            // Pop the two operands from the stack.
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();

            // Perform the calculation and push the result back onto the stack.
            int v3 = cal(v1, v2, ch);
            st.push(v3);
        }
    }
    // The final result is the top element of the stack.
    return st.top();
}

int main() {
    // Example usage
    string postfix_expression = "231*+9-";
    int result = evaluate(postfix_expression);
    cout << "The result of the postfix expression '" << postfix_expression << "' is: " << result << endl;
    return 0;
}