#include<bits/stdc++.h>

using namespace std;

int ans;

bool canWeGo(vector<vector<int>> &grid , int n , int i , int j){
    return i>=0 and j>=0 and i<n and j<n and grid[i][j]==0;
}

void f(vector<vector<int>> &grid, int n , int i , int j){
    if(i==n-1 and j==n-1){
        ans++;
        return;
    }

    grid[i][j]=2; // mark visited

    //left
    if(canWeGo(grid,n,i,j-1)){
        f(grid,n,i,j-1);
    }
    
    //up
    if(canWeGo(grid, n , i-1,j )){
        f(grid , n , i-1, j);
    }

    //right 
    if(canWeGo(grid , n ,i , j+1)){
        f(grid , n , i , j+1);
    }

    // down 
    if(canWeGo(grid, n , i+1, j)){
        f(grid , n , i+1,j);
    }

    grid[i][j]=0;       // 0 -> open and 1-> blocked

}

int ratInMaze(vector<vector<int>> &grid, int n){
    ans = 0 ;
    f(grid, n, 0 , 0);
    return ans;

}


int main(){

    vector<vector<int>> grid = {
        {0,0,1,0,0,1,0},
        {1,0,1,1,0,0,0},
        {0,0,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {1,0,1,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,0,0,0},
    };

    int n = 7;



    cout<<ratInMaze(grid,n);

    

    return 0;
}