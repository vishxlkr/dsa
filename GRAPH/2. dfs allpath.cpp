#include<bits/stdc++.h>

using namespace std;

vector<list<int>> graph;
int v;
vector<vector<int>> result;
unordered_set<int> visited;

void addEdge(int s, int d,bool bidir = true){
    graph[s].push_back(d);
    if(bidir){
        graph[d].push_back(s);
    }
}


void dfs(int curr, int end, vector<int> &path){

    if(curr == end ){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }

    visited.insert(curr);
    path.push_back(curr);
    
    for(auto neighbor : graph[curr]){
        if(not visited.count(neighbor)){
            dfs(neighbor,end,path);
        }
    }

    path.pop_back();
    visited.erase(curr);

    
    return;

}


int main(){

    cin>>v;
    graph.resize(v,list<int>());

    visited.clear();

    int e;cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        addEdge(s,d); // s, d, true;
    }

    vector<int>path;
    dfs(0,6,path);

    cout<<"output"<<endl;

    for(auto path: result){
        for(auto ele: path){
            cout<<ele<<" ";
        }cout<<endl;
    }

    

    return 0;
}