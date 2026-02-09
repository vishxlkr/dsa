#include<bits/stdc++.h>

using namespace std;

vector<string> ans;
int countt;

void permutation(string &str, int i){
    
    if(i==str.size()){
        ans.push_back(str);
        countt++;
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

    string str ;
    cin>>str;

    countt=0;
    ans.clear();

    permutation(str, 0);
    cout<<countt<<endl;

    sort(ans.begin(),ans.end());

    

    



    for(int i = 0 ; i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}

