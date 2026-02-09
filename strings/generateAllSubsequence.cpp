#include<bits/stdc++.h>

using namespace std;

void f(string &s,string current, int i ){
    if(i==s.size()){
        cout<< current <<endl;
        return;
    }
    f(s, current + s[i], i+1);
    f(s, current , i+1);

    return ;
}

int main(){

    string s = "abc";
    f(s, "",0);

    return 0;
}

// at every point , we have 2 choice , 
// either to include the current index character or not include -> will create all the subsequence