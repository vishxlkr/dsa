#include<bits/stdc++.h>

using namespace std;


bool f(int num , int *temp ){
    if(num>=0 and num<=9){
        int lastDigitOfTemp = (*temp%10);
        *temp= *temp/10;
        return ( num==lastDigitOfTemp);
    }

    bool result = (f(num/10,temp) and (num%10 == *temp%10));
    *temp = *temp/10;
    return result;
}

int main(){

    int num ;
    cin>>num;

    int anotherNum = num;
    int *temp = &anotherNum ;


    int ans = f(num , temp);  
    cout<<ans;

    return 0;
}