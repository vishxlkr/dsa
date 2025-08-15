#include<bits/stdc++.h>

using namespace std;

int grid[4][4] = {
    {0,  20, 42, 25},
    {20,  0, 30, 34},
    {42, 30,  0, 10},
    {25, 34, 10,  0}
};

int dp[10][(1<<10)];

int tsp (int curr, int mask , int n){       // O(n^2 * 2^n)
    if(mask == (1<<n)-1 ){
        return grid[curr][0];
    }

    if(dp[curr][mask] != -1) return dp[curr][mask];
    
    int ans = INT_MAX;
    for(int neigh = 0 ; neigh < n; neigh++){
        if((mask & (1 << neigh))==0){
            ans = min(ans , grid[curr][neigh] + tsp(neigh, mask | (1 <<neigh), n));

        }
    }

    return dp[curr][mask]=ans;
}

int main(){

    memset (dp, -1 , sizeof dp);
    cout<<tsp(0, 1, 4);
    

    return 0;
}