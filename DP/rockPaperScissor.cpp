#include<bits/stdc++.h>
using namespace std;

#define ld long double

ld dp[105][105][105];

ld fr (int r, int s ,int p){    // rock survival prob
    if(r==0) return 0;
    if(s==0) return 0;
    if(p==0) return 1;

    if(dp[r][s][p] > -0.9) return dp[r][s][p];

    return dp[r][s][p] =   fr(r,s-1,p)*(r*s)/(r*s+s*p+r*p) 
            + fr(r-1,s,p)*(r*p)/(r*s+s*p+r*p)
            + fr(r,s,p-1)*(s*p)/(r*s+s*p+r*p);
}


ld fs (int r, int s ,int p){    // scissor survival prob
    if(r==0) return 1;
    if(s==0) return 0;
    if(p==0) return 0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];

    return dp[r][s][p] =    fs(r,s-1,p)*(r*s)/(r*s+s*p+r*p) 
            + fs(r-1,s,p)*(r*p)/(r*s+s*p+r*p)
            + fs(r,s,p-1)*(s*p)/(r*s+s*p+r*p);
}

ld fp (int r, int s ,int p){    // paper survival prob
    if(r==0) return 0;
    if(s==0) return 1;
    if(p==0) return 0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    

    return  dp[r][s][p] =   fp(r,s-1,p)*(r*s)/(r*s+s*p+r*p) 
            + fp(r-1,s,p)*(r*p)/(r*s+s*p+r*p)
            + fp(r,s,p-1)*(s*p)/(r*s+s*p+r*p);
}

int main(){

    int r , s , p ;
    cin>>r>>s>>p;

    memset(dp , -1.0 , sizeof dp);
    ld a =  fr(r,s,p);
    memset(dp , -1.0 , sizeof dp);
    ld b =  fs(r,s,p);
    memset(dp , -1.0 , sizeof dp);
    ld c =  fp(r,s,p);

    cout<<fixed << setprecision(9) <<a<<" "<<b<<" "<<c;
    
    return 0;
}