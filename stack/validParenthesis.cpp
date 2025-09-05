#include<bits/stdc++.h>
using namespace std;


bool isValid(string s) {
        int n = s.size();
        stack<int>st;

        for(int i = 0 ; i < n ;i++){
            char ch = s[i];
            if(ch == '(' or ch=='{' or ch=='['){
                st.push(ch);
            } else {
                if(ch==')' and  ! st.empty() and  st.top()=='(' ){
                    st.pop();
                }
                else if(ch==']' and ! st.empty() and  st.top()=='[' ){
                    st.pop();
                }
                else if(ch=='}' and ! st.empty() and st.top()=='{' ){
                    st.pop();
                } else {return false;}
            }
        }

        if(st.size()==0) return true;
        return false;


    }



int main(){

    vector<string> testCases = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[()]}"
    };

    for(string s : testCases) {
        cout << s << " : " << (isValid(s) ? "Valid" : "Invalid") << endl;
    }
    

    return 0;
}