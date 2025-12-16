#include <bits/stdc++.h>

using namespace std;

int trap(vector<int> & height){
    int n = height.size();
    int left = 0; 
    int right = n-1;
    int leftMax = 0; 
    int rightMax = 0;
    int water = 0;
    
    while(left < right ){
        if(height[left]<height[right]){
            if(height[left]>=leftMax){
                leftMax = height[left];
            } else {
                water = water + leftMax - height[left];
            } 
            left++;
        } else {
            if(height[right] >= rightMax){
                rightMax = height[right];
            } else {
                water = water + rightMax- height[right];
            }
            right--;
        }
    }
    
    return water;
    
}

int main() {
    // Write C++ code here
    
    vector<int> height = {0,2,0,3,1,0,1,3,2,1};
    cout<<trap(height);
    return 0;
}




git



git quick
git quick


git quickgit quick


git quick














