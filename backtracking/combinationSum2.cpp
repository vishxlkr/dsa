#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> result;
void f(vector<int> & candidates, int target , int idx, vector<int> & subset ){
    if(target==0){
        result.push_back(subset);
        return;
    }
    if(idx==candidates.size()) return;

    //pick
    if(candidates[idx]<=target){
        subset.push_back(candidates[idx]);
        f(candidates,target-candidates[idx], idx+1, subset);
        subset.pop_back();
    }
    
    //not pick
    int j = idx+1;
    while(j<candidates.size() and candidates[j]==candidates[j-1]) j++;
    f(candidates,target, j, subset);

}


vector<vector<int>> combinationSum2(vector<int>& candidates , int target){
    result.clear();
    
    sort(candidates.begin(),candidates.end());
    vector<int>subset;
    subset.clear();
    f(candidates,target,0,subset);
    return result;
}

int main(){
    vector<int> candidates= {2,5,2,1,2};
    int target = 5;
    vector<vector<int>>ans = combinationSum2(candidates,target);

    for(int i= 0 ; i<ans.size();i++){
        for(int j = 0 ;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}