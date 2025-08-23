#include<bits/stdc++.h>
using namespace std;



int bruteforce(vector<int> &arr){
    // this will generate sum of all the subarray and compare with maxsum 
    // 0(n^2)

    int n = arr.size();
    int maxsum = INT_MIN;

    for(int i = 0 ; i < n; i++){
        int sum = 0;
        for(int j = i ; j<n;j++){
            sum = sum + arr[j];
            if(sum> maxsum) {
                maxsum = sum;
            }
        }
    }
   return maxsum;
}

int slidingWindow(vector<int>& arr){

}v


int main(){

    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    
    cout<<bruteforce(arr);

    return 0;
}