#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;


vector<ll> dp;

ll f(int n){
    if(n==0) return 1;
    // if(n==1) return 1;

    if(dp[n]!=-1) return dp[n];

    ll sum = 0;
    
    for(int i=1 ; i <= 6 ; i++ ){
        if(n-i < 0) break;
        sum = (sum%mod + f(n-i)%mod)%mod;
    }
pp
    return dp[n]=sum%mod;



}



int main(){

    int n ;
    cin>>n;

    dp.clear();
    dp.resize(n+10,-1);

    cout<<f(n);

    return 0;
}