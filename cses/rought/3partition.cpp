#include<bits/stdc++.h>

using namespace std;

int getFirstDigit(int n){
        while(n>10){
            n=n/10;
        }

        return n;
    }


int main(){

    cout<<getFirstDigit(92342);

    return 0;
}