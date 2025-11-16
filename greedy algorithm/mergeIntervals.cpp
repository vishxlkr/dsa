/*

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.
 
*/

// /* SOLUTION
// interverals are given in random order -> rearrange them
// parameter of rearrangement -> (startTime or endtime)
// if we sort on the basis of endtime , and we read the element from array from the starting , then there might be some case where we can miss merging some intervals later
// so instead of reading the array left to right -> read the array from right to left


// overall, when we sort wrt to start time , iterate the array from start to end
// and when we sort wrt to end time , iterate the array from end to start

// also keep a different result array and add the sorted array there, and iterate on interval array and compare with last element of result array



#include<bits/stdc++.h>
using namespace std;


// wrt to end time

 static bool cmp1 (vector<int>&a , vector<int> & b){
    return a[1]<b[1];           // sort on the basis of end time
}


vector<vector<int>> merge(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end(), cmp1);

    vector<vector<int> >result;
    int n = intervals.size();

    result.push_back(intervals[n-1]);// pushing the last element , as it will always come


    for(int i = n-2 ; i>=0; i--){
        vector<int>curr = intervals[i];

        if(curr[1] >= result[result.size()-1][0]){
            // merge them
            result[result.size()-1][0] = min(curr[0], result[result.size()-1][0]);
            result[result.size()-1][1] = max(curr[1], result[result.size()-1][1]);

        } else {
            result.push_back(intervals[i]);
        }
    }

    return result;

}



// wrt to start time
    bool cmp2 (vector<int> &a , vector<int> &b){
        return a[0]<b[0];               // sort wrt to start time
    }


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp2);

        vector<vector<int>> result;
        int n = intervals.size();
        result.push_back(intervals[0]);
        for(int i = 1; i <n ;i++){
            vector<int> curr = intervals[i];
            if(curr[0] <= result[result.size()-1][1]) {
                result[result.size()-1][0]= min(curr[0], result[result.size()-1][0]);
                result[result.size()-1][1]= max(curr[1], result[result.size()-1][1]);
            } else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }





int main(){

    

    return 0;
}
