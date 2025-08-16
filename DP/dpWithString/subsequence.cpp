#include<bits/stdc++.h>

using namespace std;

vector<vector<int>>  dp;

// to find only the length of longest common subsequnce 
int f(string s1, string s2 , int i , int j ){
    if(i==s1.size() || j==s2.size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i]==s2[j]){
        return dp[i][j]= 1 + f(s1,s2,i+1,j+1);
    } else {
        return dp[i][j]= max(f(s1,s2,i+1,j), f(s1,s2,i,j+1));
    }
}


int main(){

    string s1 = "abcde";
    string s2 = "abc";

    dp.resize(100, vector<int> (100,-1));

    cout<<f(s1,s2,0,0);
    

    return 0;
}



// subsequnce - we get after deleting some element from the string
// abcde -> ace, abc, ade, ....

// question -> 
// we are given 2 string and we have to find the longest common subsequence 

// M-1    
// brute forceb -> generate all subsequnce and compare

// topdown 
// at each index we have choice to include one character of a string and leave the other character of the other string
// base case -> if either of the string got finished -> resturn 0

// bottom up
//