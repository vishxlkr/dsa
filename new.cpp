#include<bits/stdc++.h>
using namespace std;






int main(){

    vector<vector<int>> v (4 , vector<int> (5, 10));

    for(int i = 0 ; i < v.size(); i++){
        for(int j = 0 ; j < v[i].size();j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}