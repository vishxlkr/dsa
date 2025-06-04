#include<bits/stdc++.h>

using namespace std;

int rabbitsInForest(vector<int> & arr){
    unordered_map<int ,int > mp;    // 5 -> 6 rabbits => 1 based indexing in map

    int result = 0;

    for(int i= 0 ; i < arr.size();i++){
        
        if( !mp[arr[i] + 1]) {
            result = result + arr[i]+1;
            if(arr[i]==0) continue;
            mp[arr[i]+1]=1;
        } else {
            mp[arr[i]+1]++;
            int key = arr[i]+1;
            int value = mp[arr[i]+1];
            if(key==value){
                mp.erase(key);
            }
        }
    }
    return result;
}

int main(){

    vector<int> rabbits = {5,5,5,5,5,5,1,1};

    cout<<rabbitsInForest(rabbits);

    return 0;
}