#include<bits/stdc++.h>

using namespace std;


int f(int i , int j , int n , int m){

    if(i>=n || j>=m) return 0;
    if(i==n-1 and j==m-1) return 1;
    
    return f(i+1,j,n,m) +  f(i,j+1,n,m);
    
}

void noOfPath(int i , int j , int n , int m , int &ans){
    if(i>=n || j>=m) return;
    if(i==n-1 and j==m-1){
        ans++;
        return;
    }

    noOfPath(i+1,j,n,m,ans);
    noOfPath(i,j+1,n,m,ans);
}

int main(){

    int n = 4;
    int m = 4;

    int answer = f(0,0,n,m);
    cout<<answer<<endl;

    ///////////////////2nd method
    int ans = 0;
    noOfPath(0,0,n,m,ans);
    cout<<ans;

    return 0;
}