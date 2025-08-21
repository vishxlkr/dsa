#include<bits/stdc++.h>

using namespace std;


pair<int,int>  f(vector<int>&arr, int k){

    int n  = arr.size();
    
    int prevsum  =0;
    for(int i=0; i<k;i++){
        prevsum = prevsum+arr[i];
    }

    int maxsum = prevsum;
    int maxidx = 0;

    int l = 1;              // start of the next window
    int r = l+k-1;          // ending of the next window

    while(r<n){
        int currsum = prevsum + arr[r] - arr[l-1];
        if(currsum > maxsum){
            maxsum = currsum;
            maxidx = l;
        }

        prevsum = currsum;
        l++;
        r++;
    }

    return {maxsum, maxidx};




}

int main(){

    vector<int> v = {7,1,2,5,8,4,9,3,6};

    int k = 3;

    pair<int,int> ans = f(v,k);



    cout<<ans.first<<" "<<ans.second;



    

    return 0;
}