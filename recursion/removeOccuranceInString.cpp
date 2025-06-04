#include<bits/stdc++.h>

using namespace std;

string f(string s, int i ){

    if(i==s.size()) return "";

    if(s[i]=='a'){
        return (""+f(s,i+1));
    } else {
        return (s[i]+f(s,i+1));
    }
}


int main(){

    string s = "axabcax";

    string ans = f(s,0);

    cout<<ans;  
    

    return 0;
}