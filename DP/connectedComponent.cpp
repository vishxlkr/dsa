#include<bits/stdc++.h>

using namespace std;


vector<list<int>> graph;
int v;
unordered_set<int> visited;
int countt ; 


void addEdge(int s, int d , bool bidir = true){
    graph[s].push_back(d);
    if(bidir) graph[d].push_back(s);
}

void dfs(int i ){
    
    visited.insert(i);

    for(auto neighbor : graph[i]){
        if(not visited.count(neighbor)){
            dfs(neighbor);
        }
    }
    return ;
}


int connectedComponent(){
    for(int i = 0 ; i < v ; i++){
        if(not visited.count(i)){
            countt++;
            dfs(i);
        }
    }
}



int main(){

    cin>>v;
    graph.resize(v , list<int> ());
    int e; cin>>e;
    countt = 0;

    while(e--){
        int s, d;
        cin>>s>>d;

        addEdge(s,d);
    }

    connectedComponent();

    cout<<countt;

    return 0;
}