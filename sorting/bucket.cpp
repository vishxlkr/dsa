#include<bits/stdc++.h>

using namespace std;

void bucketSort(vector<int> &arr ,int size){
    vector<vector<float> bucket(size, vector<float>());

    for(int i = 0 ; i < size ; i++){
        int index = arr[i]*size;
        bucket[index].push_back(arr[i]);
    }
}


int main(){

    

    return 0;
}