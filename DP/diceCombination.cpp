#include<bits/stdc++.h>

using namespace std;

vector<int> dp;
vector<int> dice = {1,2,3,4,5,6};

int f(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;

    int result = INT_MAX;

    for(int i = 0 ; i<dice.size();i++){
        result = min(result , f(n-dice[i]));
    }

    

}


int main(){

    int n ;cin>>n;

    cout<<f(n);

    return 0;
}