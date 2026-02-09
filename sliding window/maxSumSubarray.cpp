#include<bits/stdc++.h>

using namespace std;

// this is sliding window for the fixed size window 

int main(){

    vector<int> arr = {7,1,2,5,8,4,9,3,6};
    int n = arr.size();
    int k = 3;

    int prevSum = 0;

    // calculating the sum of initial window
    for(int i=0 ; i<k;i++){
        prevSum = prevSum + arr[i];
    }

    int maxsum = prevSum;

    int i = 1;              // i = 0 is already computed
    int j = i+k-1;  
    int maxidx = -1;        // to store the max window index

    while(j<n){
        int currSum = prevSum + arr[j]-arr[i-1];
        if(currSum > maxsum) {
            maxsum = currSum;
            maxidx = i;
        }
        prevSum = currSum;
        j++;
        i++;
    }

    cout<<maxsum<<" "<<maxidx;
    return 0;
}