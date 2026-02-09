#include<bits/stdc++.h>

using namespace std;

void f(vector<int> &arr, int i , int n , int sum , vector<int> &result){
    if(i==n) {
        result.push_back(sum);
        return;
    }

    f(arr,i+1,n,sum,result);
    f(arr,i+1,n,sum+arr[i],result);
    return;
}


int main(){

    
    vector<int> arr = {3,2,5};
    int n = arr.size();
    vector<int> result;

    f(arr,0,n,0,result);

    for(int i = 0 ; i<result.size();i++){
       cout<<result[i]<<' ';
    }
    return 0;
}