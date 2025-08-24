#include<bits/stdc++.h>
using namespace std;


int fruitsIntoBasket(vector<int> &arr){
    int n = arr.size();

    
}


// brute force
int bruteforce(vector<int> & arr){
    int n = arr.size();
    int count ;
    int maxcount = 0;
    for(int i = 0 ; i < n; i++){
        unordered_set<int> visited;
        count = 0;
        for(int j=i;j<n;j++){
            visited.insert(arr[j]);
            if(visited.size() > 2) break;
            count = count+1;
            if(count > maxcount) maxcount = count;
        }
    }
    return maxcount;
}




int main(){

    vector<int> arr = {0,1,2,2};      // 2

    cout<<fruitsIntoBasket(arr);



    return 0;
}