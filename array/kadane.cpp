// kadane algo

#include<bits/stdc++.h>
using namespace std;


int kadane(vector<int> & arr){
    int n = arr.size();

    int currsum = 0 ; 
    int maxsum = 0;
    for(int i =0 ; i < n;  i++){
        currsum = currsum + arr[i];
        maxsum = max(currsum , maxsum);
        if(currsum < 0) currsum = 0 ;
    }

    return maxsum;
}




int main(){

    vector<int> v = { -2,1,-3,4,-1,2,1,-5,4};   //6
    vector<int> v1 = { 5,4,-1,7,8};  //23

    cout<<kadane(v)<<endl;
    cout<<kadane(v1)<<endl;

    return 0;
}

