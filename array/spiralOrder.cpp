#include<bits/stdc++.h>

using namespace std;

void spiralOrder(vector<vector<int>> mat){
    int top = 0;
    int bottom = mat.size()-1;
    int left = 0;
    int right = mat[0].size()-1;

    int direction = 0;

    while(left <= right and top<=bottom){
        if(direction==0){           // top left to right
            for(int j= left ; j<=right ; j++){
                cout<<mat[top][j]<<" ";                     // order of i and j is important in all matrix
            } top++;
        }


        else if(direction == 1){
            for(int i = top ; i<= bottom ; i++){
                cout<<mat[i][right]<<" ";                   // order of i and j is important in all matrix
            } right --;
        }

       

        else if(direction == 2){
            for(int j = right ; j>=left ; j--){
                cout<<mat[bottom][j]<<" ";                 // order of i and j is important in all matrix
            } bottom--;
        }

        

        else if(direction==3){
            for(int i = bottom ; i>=top;i--){
                cout<<mat[i][left]<<" ";                    // order of i and j is important in all matrix
            } left ++;
        }

    
        direction = (direction+1)%4;


    }
}


int main(){

    int n , m ;
    cin>>n>>m;

    vector<vector<int>> mat(n,vector<int>(m));

    for(int i = 0 ; i < n ; i++){
        for(int j =0 ; j<m ;j++){
            cin>>mat[i][j];
        }
    }

    spiralOrder(mat);
    

    return 0;
}