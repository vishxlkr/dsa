//  here consider each bar will store some amount of water and that amount will be given by 
// min(left_max, right_max) - height[i];
//now we have to only think about how we are going to calculate this leftmax  and rightmax


#include<bits/stdc++.h>
using namespace std;


int brute(vector<int> & height){

    int water = 0;

    for(int i = 0 ; i<height.size();i++){

        int leftmax = 0 , rightmax = 0 ;

        //find leftmax
        for(int l =0; l<=i; l++){
            leftmax= max (leftmax, height[l]);
        }
        //find rightmax
        for(int r = i ; r<height.size();r++){
            rightmax = max(rightmax , height[r]);
        }

        water = water +  max(0 , min(leftmax,rightmax) - height[i]);
    }
    return water;
}



int better(vector<int> &height){
    int n = height.size();
    vector<int> leftmax(n);

    vector<int> rightmax(n);

    leftmax[0]=height[0];
    rightmax[n-1]=height[n-1];

    for(int i = 1 ; i<n;i++){
        leftmax[i] = max(height[i], leftmax[i-1]);
    }

    for(int i = n-2; i>=0; i--){
        rightmax[i] = max(height[i] , rightmax[i+1]);
    }

    int water =0;

    for(int i =0 ; i < n ; i++){
        water = water + min(leftmax[i], rightmax[i]) - height[i];
    }

    return water;



}



int main(){

    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};


   cout<<better(v);

    return 0;
}