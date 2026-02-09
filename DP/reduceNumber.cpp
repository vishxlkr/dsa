#include<bits/stdc++.h>

using namespace std;



vector<int> dp;



int topdown(int n){
    if(n==1) return 0;                             
    if(n==2) return 1;                                               
    if(n==3) return 1;

    if(dp[n]!=-1) return dp[n];
    return dp[n] = 1 + min({topdown(n-1), (n%2==0) ? topdown(n/2) : INT_MAX, (n%3==0) ?  topdown(n/3): INT_MAX});
}

int bottomup(int n){
    dp.clear();
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int i= 4; i<=n;i++){
        dp[i]= 1+min({dp[i-1] , (i%2==0) ? dp[i/2] : INT_MAX ,(i%3==0) ?  dp[i/3] : INT_MAX});
    }
    return dp[n];
}

int main(){
    
    int n = 10 ; 
    // cin >> n;


    dp.clear();
    dp.resize(n+5,-1);
    cout<<topdown(15)<<endl;

    // dp.clear();
    // dp.resize(n+5,INT_MAX);
    // cout<<bottomup(15);

    // 15 5 4 2 1

    return 0;
}