#include<bits/stdc++.h>

using namespace std;

int f(int a, int b){
    if(b>a) return f(b,a);
    if(b==0) return a;

    return f(b,a%b);

}


int main(){

    int a=12;
    int b=18;
    // cin>>a>>b;

    int ans = f(a,b);
    cout<<ans;

    return 0;
}