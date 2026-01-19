#include<bits/stdc++.h>
using namespace std;

vector<list<int>>graph;
int v;

void addEdge(int s, int d, bool bidir = true){
    graph[s].push_back(d);
    if(bidir)  graph[d].push_back(s);
}


void topoBFS(){
    vector<int> indegree(v,0);


    // calculating indegree
    for(int i = 0 ; i < v ; i++){
        for(int neighbor : graph[i]){
            indegree[neighbor]++;
        }
    }

    queue<int> qu;
    // insert into queue if indegre is zero
    for(int i = 0 ;i<indegree.size(); i++){
        if(indegree[i]==0){
            qu.push(i);
        }
    }

    cout<<"starting topo bfs"<<endl;


    while(not qu.empty()){
        int curr = qu.front();
        qu.pop();
        cout<<curr<<" ";            // to see which one resolved first

        for(int neighbor : graph[curr]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0) qu.push(neighbor);
        }
    }







}



int main(){

    cin>>v;
    graph.resize(v, list<int> ());

    int e; cin>>e;
    while(e--){
        int s , d;
        cin>>s>>d;
        addEdge(s,d,false);
    }

    topoBFS();

    

    return 0;
}