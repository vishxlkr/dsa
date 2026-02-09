#include<bits/stdc++.h>

using namespace std;


int f(vector<int> &h , int n , int i){
    if(i==n-1) return 0;
    if(i==n-2) return abs(h[i]-h[i+1]); 
    // if this line wont be added , then it wont be able to call f(i+2) from i = n-2; 

    return min(abs(h[i]-h[i+1])+f(h,n,i+1) , abs(h[i]-h[i+2]) + f(h,n,i+2));
}

int main(){

    vector<int> h = {10,30,40,20};
    int n = 4;
    int ans = f(h,n,0);
    cout<<ans;

    return 0;
}