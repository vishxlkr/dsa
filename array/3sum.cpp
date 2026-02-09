#include<bits/stdc++.h>
using namespace std;



vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin() , nums.end());

        vector<vector<int>> ans;

        for(int i = 0 ; i <n ; i++){

            // hande duplicate for the first pointer
            if(i > 0 and nums[i]== nums[i-1]) continue;

            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = nums[i] + nums[l]+ nums[r] ;

                
                if(sum == 0){
                    ans.push_back({nums[i] , nums[l] , nums[r]});

                    l++;
                    r--;

                    // handing the duplicate
                    while( l<r and nums[l]==nums[l-1]) l++;
                    while( l<r and nums[r]==nums[r+1]) r--;

                } else if(sum>0){
                    r--;
                } else {
                    l++;
                }

            }
        }

        return ans;


}


int main(){

    vector<int> v = {-1,0,1,2,-1,-4};

    vector<vector<int>> ans = threeSum(v);

    for(int i = 0 ; i< ans.size(); i++){
        for(int j = 0 ; j < ans[i].size(); j++){
            cout<<ans[i][j] <<" ";
        } cout<<endl;
    }



    

    return 0;
}
