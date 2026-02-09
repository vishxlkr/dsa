#include<bits/stdc++.h>

using namespace std;


int f(int n){
    if(n>=0 and n<=9) return n;

    return n%10 + f(n/10);
}

int main(){

    int n ; cin>>n;

    int ans = f(n);
    cout<<ans;

    return 0;
}