#include<bits/stdc++.h>
#define ll long long 

using namespace std;

vector<int> coins;

vector<int> dp;

ll fbu(int n){
    if(n==0) return 0;
    // if(n<0) return INT_MAX;

    if(dp[n]!= -2) return dp[n];
    

    ll result = INT_MAX;
    for(int i = 0 ; i < coins.size();i++){
        if(n-coins[i]<0) continue;
        result = min(result , fbu(n-coins[i]));
    }

    if(result == INT_MAX) return dp[n]= INT_MAX;
    return dp[n] = 1 + result;

}


int main(){

    int n;      cin>>n;     // no of coins 
    
    ll sum; cin>>sum;      // 

    coins.resize(n);
    dp.clear();
    dp.resize(sum+1,-2);

    for(int i =0 ; i< n;i++){
        cin>>coins[i];
    }

    ll ans = fbu(sum);

    if(ans ==INT_MAX) cout<<"-1";
    else cout<<ans;


    
    

    return 0;
}