#include<bits/stdc++.h>

using namespace std;

void f(string s, int i , int n , string temp, vector<string> &result){
    if(i==n){
        result.push_back(temp);
        return;
    }

    f(s,i+1,n,temp,result);
    f(s,i+1,n,temp+s[i],result);



    return;

}


int main(){

    string s = "abc";
    int n = s.size();
    vector<string>result;
    f(s,0,n,"",result);

    for(int i = 0 ; i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}