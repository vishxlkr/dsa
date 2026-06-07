#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> dp;

int n;
vector<int> wt;
vector<int> val;

int f(int i , int cap ){
    if(i==n or cap==0) return 0;
   

    if(dp[i][cap]!=-1) return dp[i][cap];

    int nottake = 0 + f(i+1, cap);
    int take = 0;

    if(cap >= wt[i]){
        take = val[i] + f(i+1, cap-wt[i]);
    }

    return dp[i][cap] = max(take ,nottake);
}



int main(){

    int cap;
    cin>>n>>cap;
    
    wt.clear(); wt.resize(n);
    val.clear(); val.resize(n);

    dp.clear();
    dp.resize(n+1, vector<int>(cap+1,-1));


    for(int i = 0 ; i < n ; i++){
        cin>>wt[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin>>val[i];
    }

    cout<<f(0,cap);

    return 0;
}