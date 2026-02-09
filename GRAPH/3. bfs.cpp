#include<bits/stdc++.h>

using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;



void addEdge(int s, int d , bool bidir = true){
    graph[s].push_back(d);
    if(bidir) graph[d].push_back(s);
}

void bfs(){
    queue<int> qu;
    vector<int> dist(v);
    qu.push(0);
    dist[0]=0;
    while(not qu.empty()){
        int curr = qu.front();
        qu.pop();
        for(auto neighbor: graph[curr]){
            if(not visited.count(neighbor)){
                qu.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }


    for(int i =0 ; i < v; i++){
        cout<<dist[i]<<" ";
    }

}




int main(){

    cin>>v;
    graph.resize(v,list<int>());

    int e; cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        addEdge(s,d);
    }

    bfs();

   

    return 0;
}