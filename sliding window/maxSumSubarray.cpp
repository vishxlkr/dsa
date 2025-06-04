#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int> arr = {7,1,2,5,8,4,9,3,6};
    int n = arr.size();
    int k = 3;

    int prevSum = 0;

    for(int i=0 ; i<k;i++){
        prevSum = prevSum + arr[i];
    }

    int maxsum = prevSum;

    int i = 1;
    int j = i+k-1;
    int maxidx = -1;

    while(j<n){
        int currSum = prevSum + arr[j]-arr[i-1];
        if(currSum > maxsum) {
            maxsum = currSum;
            maxidx = i;
            cout<<maxsum<<endl;
        }
        prevSum = currSum;
        j++;
        i++;
    }

    cout<<maxsum<<" "<<maxidx;
    return 0;
}