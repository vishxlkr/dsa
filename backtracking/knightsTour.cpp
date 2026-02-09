#include<bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>>& grid , int n , int i , int j){
    return i>=0 and j>=0 and i<n and j<n and grid[i][j]==-1 ;
}

vector<int> dx = {-1,+1,-2,+2,-1,+1,-2,+2};
vector<int> dy = {+2,+2,+1,+1,-2,-2,-1,-1};

void displayGrid(vector<vector<int>> & grid , int n){
    for(int i =0 ; i<n;i++){
        for(int j=0; j<n;j++){
            cout<<grid[i][j]<<"\t";
        } cout<<endl;
    }
}

void f(vector<vector<int>> & grid, int n , int i , int j,int count){

    if(count == (n*n-1)){
        grid[i][j]=count;
        displayGrid(grid , n);
        cout<<"*********"<<"\n";
        grid[i][j]=-1;
        return;
    }
    
    grid[i][j]=count;

    for(int t = 0 ;t<8;t++){
        if(isSafe(grid,n,i+dx[t],j+dy[t])){
            f(grid,n,i+dx[t],j+dy[t],count+1);
        }
    }

    grid[i][j]=-1;      // backtracking
}

void knightsTour(int n , int i , int j){
    vector<vector<int>> grid(n,vector<int>(n,-1));
    
    f(grid, n, i, j, 0);
}


int main(){
    int n = 5;
    knightsTour(n,0,0); // we can set the starting cell i,j


    return 0;
}