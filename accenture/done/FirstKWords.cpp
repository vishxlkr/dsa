/*
Problem Statement :

Print the first K words of the string.

Input: Hello I am a passionate developer
       k = 4

Output: Hello I am a

*/


#include<bits/stdc++.h>
using namespace std;



string f(string &s, int k){

    // i am a passionate developer
    stringstream ss (s);
    string ans = "";

    string result;
    

    while(ss>>ans and k--){
        result += ans;
        result+=" ";
    }

    return result;

}


int main(){

    int k =3;
    string s="i am a passionate developer";
 

    cout<<f(s,k);

    return 0;
}