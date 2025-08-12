#include<bits/stdc++.h>

using namespace std;




vector<int>dp;

int topdown(vector<int>&arr , int i){
    if(i==arr.size()-1) return arr[i];
    if(i==arr.size()-2) return max(arr[arr.size()-1],arr[arr.size()-2]);

    if(dp[i] != -1) return dp[i];

    return dp[i] =  max(arr[i]+topdown(arr,i+2), 0 +topdown(arr,i+1));

}


int main(){

    dp.clear();
    dp.resize(105,-1);

    vector<int> nums  = {1,2,4,5,3,7,4,3};

    cout<< topdown(nums,0);

    

    return 0;
}