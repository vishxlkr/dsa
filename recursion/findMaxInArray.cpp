#include<bits/stdc++.h>

using namespace std;

int f(vector<int> & arr, int i){
    if(i==arr.size()-1) return arr[i] ;

    return max(f(arr,i+1),arr[i]);
    
}


int main(){

    vector<int> arr = {3,6,8,2,6,3,1};

    int ans = f(arr,0);
    cout<<ans;
    return 0;
}