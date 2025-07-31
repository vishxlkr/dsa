#include<bits/stdc++.h>

using namespace std;


void f(vector<int> & arr, int i , vector<int> & current , vector<vector<int>> & result){
    if(i==arr.size()) {
        result.push_back(current);
        return;
    }

    current.push_back(arr[i]);
    f(arr,i+1,current,result);

    current.pop_back();
    f(arr,i+1,current,result);



    return;


}

int main(){


    vector<int>arr = {1,2,3};
    vector<vector<int>> result;
    // result.clear();
    vector<int> current;
    // current.clear();

    f(arr, 0 , current, result );

    for(int i = 0 ; i< result.size();i++){
        for(int j = 0; j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        } cout<<endl;
    }
    

    return 0;
}