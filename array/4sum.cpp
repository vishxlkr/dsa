#include<bits/stdc++.h>
using namespace std;



vector<vector<int>> FourSum (vector<int> & nums ,int target){
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin() , nums.end());

    for(int i = 0 ;  i < n ; i++){

        if(i>0 and nums[i]==nums[i-1]) continue;        // imp : only remember that i should be greater that initial condition

        for(int j = i+1 ; j < n ; j++){

            if(j>i+1 and nums[j]==nums[j-1]) continue;      // imp : only remember that j should be greater that initial condition
             
            int p = j+1; int q = n-1;
            while(p<q){
                long long sum =(long long) nums[i]  + nums[j] + nums[p] + nums[q] ; 

                if(sum == target){
                    vector<int> temp = {nums[i]  , nums[j] , nums[p] , nums[q]};
                    ans.push_back(temp);
                    p++;
                    q--;

                    while(p<q and nums[p] == nums[p-1]) p++;        // imp : only remember that p<q
                    while(p<q and nums[q] == nums[q+1]) q--;        // imp : only remember that p<q

                } else if(sum < target){
                    p++;
                } else if(sum > target){
                    q--;
                }
            }

        }
    }

    return ans;
}


int main(){

    vector<int> arr = {7,-8,-7,2,-7,-7,10,-6,10,-9,2,-7,-4,-7};
    int target = -22;

    vector<vector<int>> ans = FourSum(arr , target);
    for(int i = 0 ; i< ans.size(); i++){
        for(int j = 0 ;j < ans[i].size() ; j++){
            cout<<ans[i][j] << " ";
        } cout<<endl;
    }

    return 0;
}

