#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

vector<ll> dp;
vector<int> coins;

ll f(ll sum){
    if(sum==0) return 1;
    if(sum < 0) return 0;
    if(dp[sum]!=-1) return dp[sum];
    ll ans = 0;
    for(int i = 0 ; i<coins.size();i++){
        if(sum - coins[i] < 0) continue;
        ans = (ans % mod + f(sum - coins[i])% mod)% mod;
    }
    return dp[sum]=  ans % mod;
}


int main(){

    int n ; 
    cin>>n;

    ll sum ;
    cin>>sum;

    coins.clear();
    coins.resize(n);
    

    for(int i = 0 ; i < n ;i++){
        cin>>coins[i];
    }

    dp.clear();
    dp.resize(sum+1,-1);


    cout<<f(sum);

    return 0;
}