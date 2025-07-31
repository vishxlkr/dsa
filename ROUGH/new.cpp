#include<bits/stdc++.h>

using namespace std;

vector<list<int>> graph;

int v;

void addEdge(int s ,int d , bool bidir= true){
    graph[s].push_back(d);
    if(bidir){
        graph[d].push_back(s);
    }
}

void display(){
    for(int i = 0 ; i<graph.size(); i++){
        cout << i << "->";
        for(auto ele: graph[i]){
            cout << ele <<" ";
        }
        cout<<endl;
    }
}


vector<vector<int>> result;
unordered_set<int> visited;
void dfs(int curr , int end , vector<int> &path ){
    if(curr == end ){
        // 
        path.push_back(end);
        result.push_back(path);
        return ;
    }

    visited.insert(curr);
    path.push_back(curr);
    for(auto ele : graph[curr]){
        if(not visited.count(ele)){
            dfs(ele,end,path);
        }
    }

    path.pop_back();
    visited.erase(curr);
    return ;
}




int main(){

    cin>>v;     
    graph.resize(v, list<int> ());
    visited.clear();
    int e; cin>>e;
    while(e--){
        int s, d, wt;
        cin>>s>>d>>wt;

        addEdge(s,d,wt);
    }

    

    //dfs
    vector<int> path;
    // dfs();
    
    
    return 0;
}