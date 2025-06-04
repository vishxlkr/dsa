#include<bits/stdc++.h>

using namespace std;

void f(string str,int i , string temp , vector<string>& li , vector<string>&combination){
    if(i==str.size()){
        li.push_back(temp);
        return;
    }

    int digit = str[i]-'0';
    if(digit<2){
        f(str,i+1,temp,li,combination);
        return;
    }

    for(int j=0 ;j<combination[digit].size();j++){
        f(str,i+1, temp+combination[digit][j], li,combination);
    }
    return;

}


int main(){

    string str = "89";
    vector<string> v(10);
    v ={ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    vector<string> li;
    f(str,0,"",li,v);

    for(int i = 0 ; i<li.size();i++){
        cout<<li[i]<<" ";
    }

    return 0;
}