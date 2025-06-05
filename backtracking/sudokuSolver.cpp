#include<bits/stdc++.h>

using namespace std;







bool isSafe(vector<vector<char>> & board, int r , int c, int num){
    // check row
    for(int col = 0 ; col<9 ; col++){
        if(board[r][col]-'0'==num) return false;
    }

    // check col
    for(int row = 0 ; row <9; row++){
        if(board[row][c]-'0'==num) return false;
    }

    // check big cell
    int x = (r/3)*3;
    int y = (c/3)*3;

    for(int row = x; row<x+3;row++){
        for(int col=y;col<y+3;col++){
            if(board[row][col]-'0'==num) return false;
        }
    }


    return true;
}

bool f(vector<vector<char>>&board, int r , int c ){
    if(r==9) return true;
    if(c==9) return f(board,r+1,0);
    if(board[r][c]!='.') return f(board,r,c+1);

    for(int k = 1 ; k <= 9 ; k++ ){
        if(isSafe(board,r,c,k)){
            board[r][c]='0'+k;

            bool r = f(board,r,c+1);
            if(r) return true;

            board[r][c] = '.';
        }
    }
}





bool sudokuSolver(vector<vector<char>> &board){
    return f(board,0,0);   // this function find solution from 0,0 to n-1,n-1
}


int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.',},
        {'6','.','.','1','9','5','.','.','.',},
        {'.','9','8','.','.','.','.','6','.',},
        {'8','.','.','.','6','.','.','.','3',},
        {'4','.','.','8','.','3','.','.','1',},
        {'7','.','.','.','2','.','.','.','6',},
        {'.','6','.','.','.','.','2','8','.',},
        {'.','.','.','4','1','9','.','.','5',},
        {'.','.','.','.','8','.','.','7','9',},
    };

    cout<<sudokuSolver(board);

    

    return 0;
}