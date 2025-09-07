#include<bits/stdc++.h>
using namespace std;

#define ll long long

// question
//Given an integer array arr and an integer k, find the maximum sum of any subarray of size k such that all elements in the subarray are distinct.
// If no such subarray exists, return 0.

    long long maximumSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> freq;        // frequency map
        ll windowsum = 0;
        ll maxsum = 0;
        int left = 0;

        for(int right = 0; right < n ; right++){
            windowsum += arr[right];
            freq[arr[right]]++;

            // shrink the window
            if(right - left +1 > k){
                freq[arr[left]]--;
                windowsum -= arr[left];

                // erase the element if it has 0 frequency
                // *** by doing this , we are ensuring that all different element should be present 
                if(freq[arr[left]]==0){
                    freq.erase(arr[left]);
                }

                left++;
            }

            // check if the window is valid

            if((right-left +1 == k) and (freq.size() ==k) ){        // first condition to skip the inital forming of the window
                maxsum = max(maxsum , windowsum);
            }


           

        }

         return maxsum;

        
    }

int main(){

    vector<int> arr = {1,3,54,54,23,2};
    int k =2;

    maximumSubarraySum(arr, k);

    return 0;
}
