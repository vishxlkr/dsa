#include<bits/stdc++.h>

using namespace std;

void f(vector<int> & arr, int i){
    if(i==arr.size()) return ;
    cout<<arr[i]<<" ";
    f(arr,i+1);
}


int main(){

    vector<int> arr = {3,6,8,2,6,3,1};

    f(arr,0);

    return 0;
}