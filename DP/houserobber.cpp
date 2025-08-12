#include<bits/stdc++.h>

using namespace std;




vector<int>dp;

int topdown(vector<int>&arr , int i){
    if(i==arr.size()-1) return arr[i];
    if(i==arr.size()-2) return max(arr[arr.size()-1],arr[arr.size()-2]);

    if(dp[i] != -1) return dp[i];

    return dp[i] =  max(arr[i]+topdown(arr,i+2), 0 +topdown(arr,i+1));

}

int bottomup(vector<int> &arr){
    int n = arr.size();
    if(n==1) return arr[0];
    
    dp[n-1] = arr[n-1];
    dp[n-2] = max(arr[n-1],arr[n-2]);

    for(int i = n-3; i>=0;i--){
        dp[i]= max(dp[i+2]+arr[i], 0+dp[i+1]);
    }

    return dp[0];


    
}


int main(){

    dp.clear();
    dp.resize(105,-1);

    vector<int> nums  = {2,7,9,3,1}; //output = 12

    cout<< topdown(nums,0)<<endl;
    cout<< bottomup(nums)<<endl;

   


    

    return 0;
}