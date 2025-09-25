/*

Input: 
A single line of text containing words separated by spaces. The input string consists of only printable ASCII characters. 

Output: 
The string with words reversed in order. 

Example: 
Input: Hello 
World 

Output: 
World Hello

*/





#include<bits/stdc++.h>
using namespace std;






int main(){

    string s = "Hello World i am vishal";

    stringstream ss(s);

    string temp;
    vector<string> v;

    while(ss >> temp){
        v.push_back(temp);
    }

    for(int i = v.size()-1 ; i>=0;i--){
        cout<<v[i]<<" ";
    }

    return 0;
}