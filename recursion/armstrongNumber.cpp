#include<bits/stdc++.h>

using namespace std;


int f(int n , int d ){
    if(n>=0 and n<=9) return pow(n,d);

    int num = n%10;
    return pow(num,d) + f(n/10,d);

}


int main(){

    int n = 370;
    int d= 0; 
    int temp = n;
    while(temp>0){
        d++;
        temp = temp/10;
    }

    int output = f(n, d);

    if(output==n){
        cout<<"yes";

    } else {
        cout<<"no";
    }

    return 0;
}