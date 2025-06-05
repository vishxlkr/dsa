#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> grid;
vector<vector<string>> result;

bool canPlaceQueen(int row , int col ,int n){
    //columm check
    for(int i = row -1; i>=0;i--){
        if(grid[i][col]=='Q') {
            // we are attacked 
            return false;
        }
    }
    
    // left diagonal check
    for(int i = row-1,  j = col-1 ; i >=0 and j>=0 ; i--,j--){
        if(grid[i][j]=='Q'){
            // we are attacked
            return false;
        }
    }

    // right diagonal check
    for(int i = row-1 , j = col+1; i>=0 and j<n;i--,j++){
        if(grid[i][j]=='Q'){
            // we are attacked
            return false;
        }
    }

    return true;    // no attack
}

void f(int row , int n){
    if(row==n){
        vector<string> temp;
        for(int i = 0 ; i<n;i++){
            string res = "";
            for(int j = 0 ; j< n;j++){
                res += grid[i][j];
            }cout<<endl;
            temp.push_back(res);
            result.push_back(temp);
        }

        return;
    }



    for(int col=0 ; col<n;col++){
        if(canPlaceQueen(row ,col ,n)){
            grid[row][col]='Q';
            f(row+1,n);
            grid[row][col]='.';
        }
    }
}



void nqueens(int n){
    grid.resize(n,vector<char>(n,'.'));
    f(0,n);
}



int main(){
    nqueens(4);

    return 0;
}