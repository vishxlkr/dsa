#include<bits/stdc++.h>
using namespace std;

vector<int> dp;

int ftd(int n){
    if(n== 0|| n==1) return n;

    if(dp[n] != -1) return dp[n];



    return dp[n]= ftd(n-1) + ftd(n-2);
}

// 0 1 1 2 3 5 8 13


int fbu(int n){

    dp[0]=0;
    dp[1]=1;

    for(int i = 2; i <= n; i++){
        dp[i]= dp[i-1]+dp[i-2];
    }

    return dp[n];

}

int f(int n){
    int prev1 = 1; 
    int prev2 = 0;

    int curr ;

    for(int i = 2 ; i <= n ; i++){
        curr = prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }

    return curr;
}


int main(){
    
    int n = 12;

    dp.clear();
    dp.resize(n+5, -1);

    cout<<fbu(n)<<endl;

    dp.clear();
    dp.resize(n+5, -1);


    cout<<ftd(n)<<endl;

    cout<<f(n);


    

    return 0;
}