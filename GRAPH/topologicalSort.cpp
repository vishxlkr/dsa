#include<bits/stdc++.h>

using namespace std;

vector<list<int>> graph;                                    // this is graph 
int v;                                              // no of nodes

void addEdge(int s, int d, bool bidir= true){            // adding the edge to the graph
    graph[s].push_back(d);
    if(bidir)graph[d].push_back(s);
}

void topobfs(){
    vector<int> indegree(v,0);
    for(int i =0;i<v;i++){                              // for calculating indegree
        for(auto neighbor:graph[i]){
            indegree[neighbor]++;
        }
    }

    queue<int> qu;
    unordered_set<int>visited;
    for(int i = 0; i<v;i++){
        if(indegree[i]==0) {
            qu.push(i);
            visited.insert(i);
        }
    }

    cout<<"starting topobfs"<<endl;             // starting topological sort from here

    while(not qu.empty()){
        int curr = qu.front();
        cout<<curr<<" ";
        qu.pop();
        for(auto neighbor: graph[curr]){
            if(not visited.count(neighbor)){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    qu.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }
}


int main(){

    cin>>v;
    graph.resize(v,list<int>());

    int e;cin>>e;               // no of edges
    while(e--){
        int s, d; cin>>s>>d;
        addEdge(s,d,false);
    }

    topobfs();
    return 0;
}