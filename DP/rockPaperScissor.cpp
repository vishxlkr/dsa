#include<bits/stdc++.h>

using namespace std;

int dp[105][105][105];

double f1 (int r, int s ,int p){    // rock survival prob
    if(r==0) return 0;
    if(s==0) return 0;
    if(p==0) return 1;

    return    f1(r,s-1,p)*(r*s)/(r*s+s*p+r*p) 
            + f1(r-1,s,p)*(r*p)/(r*s+s*p+r*p)
            + f1(r,s,p-1)*(s*p)/(r*s+s*p+r*p);

}



int main(){

    int n = 3; 
    vector<int> forest = {2,1,2};

    int a = f1(r,s,p);

    

    return 0;
}