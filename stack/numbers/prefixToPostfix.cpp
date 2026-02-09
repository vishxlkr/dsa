#include<bits/stdc++.h>

using namespace std;

// This function evaluates a prefix expression and returns the resulting infix expression.
string evaluate(string pre) {
    stack<string> st;

    // Reverse the string to process it from right to left, which is standard for prefix evaluation.
    reverse(pre.begin(), pre.end());

    for (int i = 0; i < pre.size(); i++) {
        char ch = pre[i];
        if (isdigit(ch)) {
            // If the character is a digit, convert it to a string and push it onto the stack.
            st.push(string(1, ch));
        } else {
            // If the character is an operator, pop the two operands from the stack.
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();

            // Form a new string by concatenating the operands and the operator.
            // This is the infix representation: (operand1 operator operand2)
            string newString = "(" + v1 + string(1, ch) + v2 + ")";
            st.push(newString);
        }
    }

    // The final result is the top element of the stack.
    return st.top();
}

int main() {
    // Example usage with a prefix expression
    string prefix_expression = "*+234";
    string infix_result = evaluate(prefix_expression);
    cout << "The infix equivalent of the prefix expression '" << prefix_expression << "' is: " << infix_result << endl;
    return 0;
}