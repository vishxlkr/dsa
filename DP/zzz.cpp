#include<bits/stdc++.h>
using namespace std;






int main(){

    vector<int> nums= {0,1,0,3,2,3};
    int n = nums.size();

    for(int i = 0 ; i < n; i++){
            int ans= 0;
            for(int j = i ; j < n ;j++){
                cout<<nums[j]<< " ";
            } cout<<endl;
        }

    return 0;
}