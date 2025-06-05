#include<bits/stdc++.h>

using namespace std;

void permutation(string &str, int i){
    if(i==str.size()){
        cout<<str<<endl;
    }

    unordered_set<char> visited;


    for(int idx = i ; idx < str.size();idx++){
        if(visited.count(str[idx])) continue;

        visited.insert(str[idx]);

        swap(str[idx],str[i]);
        permutation(str,i+1);
        swap(str[idx],str[i]);

    }
}

// i -> fixing index of the character
// idx -> swaping index of the character

int main(){

    string str = "abc";
    permutation(str, 0);

    return 0;
}