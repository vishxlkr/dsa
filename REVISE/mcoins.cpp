#include<bits/stdc++.h>
using namespace std;


vector<int> dp;

bool f(int n , int k , int l){
    // if(n==1 or n==k or n==l) return true;
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
  

    dp.clear();
    int mx = *max_element(coins.begin(), coins.end());

    dp.resize(mx+1, -1);



    for(int i = 0 ;  i < m; i++){
        
        

        

        cout << (f(coins[i], k, l) ? 'A' : 'B');
    }

    
    

    return 0;
}