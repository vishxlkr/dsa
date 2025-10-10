#include<bits/stdc++.h>

using namespace std;


int maxOnes (vector<int> &arr, int k ){
    int left =0;
    int right =0;
    int zeros =0;
    int maxlen =0;


    while(right < arr.size()){
        if(arr[right]==0){
            zeros++;
        }

        while(zeros > k){
            if(arr[left]==0){
                zeros--;
            }
            left++;
        }
        maxlen = max (maxlen , right - left + 1);
        right ++;
    }
    return maxlen;
}


int main(){

    vector<int> v = {1,0,1,1,1,0,1,1,0,0,0,0,1,1,1,1};
    int k = 2;

    int ans = maxOnes(v,k);

    cout<<ans;

    return 0;
}