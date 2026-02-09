#include<bits/stdc++.h>

using namespace std;




int main(){

    vector<int> v = {6,5,3,2,8,10,9};
    int k = 3;
    priority_queue<int , vector<int> , greater<int> > pq;
    vector<int > ans;
    int i = 0 ;
    while(i<v.size()){
        pq.push(v[i]);
        if(pq.size()>k){
            ans.push_back(pq.top());
            pq.pop();
        }
        i++;
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    for(int i = 0 ; i < v.size();i++){
        cout<<ans[i]<<" ";
    }
   return 0;
}