#include<bits/stdc++.h>

using namespace std;

string repeatLimit (string s, int k){
    unordered_map<char,int> mp;
    for(int i = 0 ; i < s.size();i++){
        mp[s[i]]++;
    }

    priority_queue< pair<char,int> > pq;

    for(auto ele : mp){
        pq.push({ele.first,ele.second});
    }

    string result = "";

    while(not pq.empty()){
        auto largest = pq.top();
        pq.pop();
        int len = min(k , largest.second);
        for(int i = 0 ; i<len ; i++){
            result += largest.first;
        }

        auto secondLargest=  pq.top();
        if(largest.second > len ){
            if(not pq.empty()){
                // secondLargest = pq.top();
                pq.pop();
                result += secondLargest.first;
            } else {
                return result;
            }
            if(secondLargest.second -1 > 0) pq.push({secondLargest.first, secondLargest.second-1});
            pq.push({largest.first, largest.second-len});
        }
    } 
    return result; 
}


int main(){

    string s = "bbbbabbb"; 
    int repeat = 3;  

    string ans = repeatLimit(s,repeat);
    
    cout<<ans;

    return 0;
}