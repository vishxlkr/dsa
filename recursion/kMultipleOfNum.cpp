#include<bits/stdc++.h>

using namespace std;

void f(int n , int k){
    if(k==0) return;

    f(n,k-1);
    cout<<n*k<<" ";
}


int main(){

    int n = 12; 
    int k = 5;

    f(n,k);

    return 0;
}