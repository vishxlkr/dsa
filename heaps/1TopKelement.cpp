#include<bits/stdc++.h>

using namespace std;




int main(){
    int n ;
    n = 7;
    vector<int> v={1,2,3,4,5,6,7,8,9};
    

    priority_queue<int> pq;
    int t=0;
    while(t<v.size()){
        pq.push(v[t]);

        if(pq.size()>3){
            pq.pop();
        }
        t++;
    }

    cout<<pq.top();



    return 0;
}