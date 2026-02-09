#include<bits/stdc++.h>

using namespace std;




int main(){

    vector<int>v = {10,1,2,20,5,8};
    priority_queue<int , vector<int>  , greater<int>> pq;
    
    for(int i =0 ;i<v.size();i++){
        pq.push(v[i]);
    }

    v.clear();
    while(not pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }

    for(int i =0  ; i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}