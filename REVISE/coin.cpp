#include<bits/stdc++.h>
using namespace std;


vector<int> dp;

vector<int> getdigits(int n){
    vector<int> digits;
    while(n!=0){
        if(n%10!=0) digits.push_back(n%10);
        n/=10;
    }

    return digits;
}

int f(int n){
    if( n==0) return 0;
     if( n<=9) return 1;


    if(dp[n]!=-1) return dp[n];

    vector<int> digits = getdigits(n);

    int result = INT_MAX ;

    for(int i = 0 ; i< digits.size(); i++){
        // if(digits[i]==0) continue;
        result = min(result , f(n-digits[i]));
    }
    return dp[n]=1+result;
}



int main(){

    int n = 27;

    dp.clear();
    dp.resize(1000005,-1);

    cout<<f(n);
    

    return 0;
}