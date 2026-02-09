#include<bits/stdc++.h>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string s: strs){
            string key = s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto it : mp){
            result.push_back(it.second);    // here we are pushing vectors into another vector
        }

        return result;

    }



int main(){

    vector<string> str =  {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = groupAnagrams(str);

    for(auto v : ans){
        for(auto ele : v){
            cout<<ele<<" ";
        }cout<<endl;
    } 


 
    return 0;
}