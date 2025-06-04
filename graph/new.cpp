#include<bits/stdc++.h>

using namespace std;




int main(){

    string s="A man, a plan, a canal: Panama";

    string clear = "";

    for(int i = 0; i<s.size();i++){
        if(isalnum(s[i])){
            clear += tolower(s[i]);
        }
    }


    clear=="amanaplanacanalpanama" ? cout<<true: cout<<false;
    return 0;
}