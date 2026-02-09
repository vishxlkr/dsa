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





int fbu (string s1, string s2 , int i , int j){

    for(int i = s1.size()-1 ; i>=0;i--){
        for(int j = s2.size()-1 ; j>=0;j--){
            if(s1[i]==s2[j]){
                 dp[i][j]= 1 + dp[i+1][j+1];
            } else {
                dp[i][j]= max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    
    

    return dp[0][0];

}


//


int main(){

    string s1 = "abcde";
    string s2 = "abce";

    // for top down
    dp.resize(1005, vector<int> (1005,-1));    // we need to initialize by -1 in topdown
    cout<<f(s1,s2,0,0)<<endl;


    dp.clear();

    //for bottom up
    dp.resize(1005, vector<int>(1005,0));       // we need to initialize by 0 for bottomup
    cout<<fbu(s1,s2,0,0);

    

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