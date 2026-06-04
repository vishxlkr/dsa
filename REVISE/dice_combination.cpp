#include<bits/stdc++.h>
using namespace std;


vector<int> dp;

int f(int n){
    if(n==0) return 1;
    // if(n==1) return 1;

    int sum = 0;
    
    for(int i=1 ; i <= 6 ; i++ ){
        if(n-i < 0) break;
        sum = sum + f(n-i);
    }

    return sum;



}



int main(){

    int n = 3;

    dp.clear();
    dp.resize(10000005,-1);

    cout<<f(n);

    return 0;
}