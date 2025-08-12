#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<int> level;

void dfsLevel (int node , int parent , int currlevel){
    level[node]= currlevel;

    for(int child : tree[node]){
        if(child != parent)
        dfsLevel(child, node, currlevel+1);
    }
}



int diameter(int node){
    
}



int main(){

    int n ; // no of nodes 
    cin>>n;

    tree.resize(n+1);
    level.resize(n+1,0);
    
    // tree construction
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
    }

    //assigning level
    dfsLevel(1,-1,0);


    // counting diameter

    






    for(int i = 1 ; i < n+1;i++){
        cout<<level[i]<<" ";
    }



    

    return 0;
}