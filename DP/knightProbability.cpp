#include<bits/stdc++.h>

using namespace std;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2,  2,  1, -1, -2, -2, -1}; 

double dp[30][30][105];

double f(int n, int i, int j, int k) {
    if (i < 0 || j < 0 || i >= n || j >= n) return 0;
    if (k == 0) return 1;

    if (dp[i][j][k] > -0.9) return dp[i][j][k];

    double ans = 0.0; 
    for (int t = 0; t < 8; t++) {
        ans += f(n, i + dx[t], j + dy[t], k - 1) * 0.125;
    }
    return dp[i][j][k] = ans;
}


int main(){

    int n=3 ; // size of chess board (square)

    // cin>>n;

    int k = 2;
    memset(dp,-1,sizeof dp);

    cout<< f(n, 0 , 0 , k);
    

    return 0;
}