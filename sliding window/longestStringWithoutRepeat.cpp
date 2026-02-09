#include<bits/stdc++.h>
using namespace std;



// longest substring without reapeating character

int longestSubstringWithoutRepeat(string &s){
    int n = s.size();
    int l =0 ; int r =0;

    int  i = 0; int j=0;    // to print the string

    unordered_map<char,int> mp;     // we will store the char and index where it was found last time
    int maxlen = 0;

    while(r<n){
        if(mp.find(s[r])!= mp.end()){
            l = max(l,mp[s[r]]+1);          // we are taking max because different character have different mp[s[r]] -> hence we can get less l
        }

        mp[s[r]] = r;
        // maxlen = max(maxlen , r-l+1);
        if(r-l+1 > maxlen){
            maxlen = r-l+1;
            i = l;
            j = r;
        }
        r++;
    }

    // print the string
    for(int t = i ; t<=j;t++){
        cout<<s[t];
    }   
    return maxlen;

}


// brute foce
string bruteforce(string & s){
    int n = s.size();
    int i = 0; int j= 0;
    int maxlen= 0;
    string ans ;
    unordered_set<char> visited;

    for(int i = 0 ; i < n; i++){
        visited.clear();
        
        string temp="";
        for(int j = i;j<n;j++){
            if(visited.count(s[j])){
                break;
            }
            visited.insert(s[j]);
            temp=temp+s[j];
            if(temp.size()>maxlen){
                maxlen = temp.size();
                ans = temp;
            }
        }
    }
    return ans;
}


int main(){

    string s = "cadbzabcd";

    cout<<bruteforce(s)<<endl;
    cout<<longestSubstringWithoutRepeat(s);

    

    return 0;
}