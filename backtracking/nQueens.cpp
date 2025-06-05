#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> grid;
vector<vector<string>> result;

bool canPlaceQueen(int row ,int col , int n){
    //col check
        for(int i = row -1; i >=0; i--){
            if(grid[i][col]=='Q') return false;
        }

        // left diagonal
        for(int i = row -1 , j =col-1; i>=0 and j>=0;i--,j--){
            if(grid[i][j]=='Q') return false;
        }


        // right diagonal
        for(int i = row-1,j=col+1; i>=0 and j <n ; i--,j++){
            if(grid[i][j]=='Q') return false;
        }

        return true;
}

void f(int row , int n){
    if(row==n){
        vector<string> temp;
        for(int i = 0 ; i<n;i++){
            string res= "";
            for(int j = 0 ;j<n;j++){
                res +=grid[i][j];
            }
            temp.push_back(res);
        } 
        result.push_back(temp);
        return;
    }

    for(int col = 0 ; col < n; col++){
        if(canPlaceQueen(row, col , n)){
            grid[row][col]='Q';
            f(row+1,n);
            grid[row][col]='Q';
        }
    }

}

vector<vector<string>> solveNQueens(int n) {
        grid.resize(n,vector<char>(n,'.'));
        f(0,n);
        return result;
    }


int main(){

    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);
    for(int i =0 ; i<result.size();i++){
        for(int j = 0  ; j<result[0].size();j++){
            cout<<result[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}