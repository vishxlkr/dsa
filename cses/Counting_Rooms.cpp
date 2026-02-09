#include<bits/stdc++.h>

using namespace std;


int n , m;
int ans ;

void dfs(vector<vector<char>> &grid , int i , int j){
    
    if( i<0 or j<0 or i>=n or j>=m or grid[i][j]=='#' or grid[i][j]=='*') return ;
    if(grid[i][j] == '.' )  grid[i][j]='*';
    dfs(grid, i+1,j);
    dfs(grid, i-1,j);
    dfs(grid, i,j+1);
    dfs(grid, i,j-1);
}

void connectedComponent (vector<vector<char>> &grid){

    for(int i = 0 ; i < n ;i++){
        for(int j = 0; j<m ; j++){
            if(grid[i][j]=='.'){
                ans++;
                dfs(grid , i , j);
            }
        }
    }
}

int main(){

    cin>>n>>m;
    vector<vector<char>> grid;
    grid.resize(n, vector<char>(m));

    for(int i = 0 ; i <n ; i++){
        for(int j = 0 ; j<m ; j++){
            cin>>grid[i][j];
        }
    }
    ans  = 0;
    connectedComponent(grid);
    cout<<ans;

    return 0;
}