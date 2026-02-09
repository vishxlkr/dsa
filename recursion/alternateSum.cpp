#include<bits/stdc++.h>

using namespace std;


int f(int n){
    if(n==1) return 1;

    return f(n-1)  + ((n%2==0)? -n:n);
}

int main(){

    int n;
    cin>>n;

    int ans = f(n);

    cout<<ans;

    return 0;
}