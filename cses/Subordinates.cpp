#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<int> subordinate ;

int dfs(int node){

    int count = 0;
    for(int child : tree[node]){
        count = count + 1 + dfs(child);
    }

    subordinate[node]= count;
    return count;

}


int main(){
    int n; cin>>n;
    tree.resize(n+1);
    subordinate.resize(n+1,0);


    // construction of the tree
    for(int emp = 2; emp < n+1; emp++){
        int boss; 
        cin>>boss;
        tree[boss].push_back(emp);
    }

    // filling the subordinate 
    dfs(1);

    //output
    for(int i = 1 ; i < (int)subordinate.size();i++){
        cout<<subordinate[i]<<" ";
    }
    

    return 0;
}