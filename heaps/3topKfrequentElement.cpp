#include<bits/stdc++.h>
#define pp pair<int,int>

using namespace std;




int main(){
    int k = 4;
    vector<int> v = {1,1,1,2,3,3,4,4,4,4};//4 1 3 2

    map<int,int> mp;
    for(int i = 0 ; i < v.size();i++){
        mp[v[i]]++;
    }
    
    

    priority_queue<pp> pq;
    for(auto ele : mp){
        pq.push({ele.second,ele.first});
        if(pq.size()>k){
            pq.pop();
        }
    }

    vector<int> ans ; 
    while(not pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }

    for(int i = 0 ; i < ans.size();i++){
        cout<<ans[i]<<" ";
        
    }
    return 0;
}