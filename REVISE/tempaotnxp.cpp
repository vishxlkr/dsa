#include<bits/stdc++.h>
using namespace std;


vector<int> dp;

bool f(int n , int k , int l){
    if(n==1 or n==k or n==l) return true;
    if(n==0) return false;
    

    if(dp[n]!=-1) return dp[n];


    return dp[n]= !(
        (n>=1 ? f(n-1,k,l) : 1)
        and 
        (n>=k ? f(n-k,k,l) : 1)
        and 
        (n>=l ? f(n-l,k,l) : 1)
    
    );

}





int main(){

    

    int k , l, m;

    cin>>k>>l>>m;
    vector<int> coins(m);
    for(int i = 0 ; i<m ; i++){
        cin>>coins[i];
    }
    for(int i = 0 ; i<m ; i++){
        cout<<coins[i]<< " ";
    }

    dp.clear();



    for(int i = 0 ;  i < m; i++){
        
        dp.resize(coins[i]+1,-1);

        

        cout<<f(coins[i],k,l);
    }

    
    

    return 0;
}