#include<bits/stdc++.h>

using namespace std;

void f(vector<int>&arr, int i , int n , vector<vector<int>> &result, vector<int>& temp){
    if(i==n) {
        result.push_back(temp);
        return;
    }

    f(arr,i+1,n,result,temp);
    temp.push_back(arr[i]);
    f(arr,i+1,n,result,temp);
    temp.pop_back();

    return;
}


int main(){

    vector<int> arr = {3,2,5};
    int n = arr.size();
    vector<vector<int>> result;
    vector<int> temp;

    f(arr,0,n,result,temp);

    for(int i = 0 ; i<result.size();i++){
        for(int j = 0 ; j<result[i].size();j++){            // imp -> result[i] not result[0]
            cout<<result[i][j]<<" ";
        } cout<<endl;
    }
    return 0;
}
