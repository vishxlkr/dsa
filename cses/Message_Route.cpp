#include<bits/stdc++.h>

#define ll long long

using namespace std;

ll n ,m ; 
vector<list<ll>> graph;
unordered_set<ll> visited;
vector<ll> dist;
vector<ll> parent;

void addEdge(int s, int d, bool bidir = true){
    graph[s].push_back(d);
    if(bidir) graph[d].push_back(s);
}


void bfs(int src ,int end){
    queue<int> qu;
    qu.push(src);
    visited.insert(src);
    dist[src]=0;

    parent[src]=-1;

    while(not qu.empty()){
        int curr = qu.front();
        qu.pop();

        for(auto neighbor : graph[curr]){
            if(not visited.count(neighbor)){
                qu.push(neighbor);
                visited.insert(neighbor);
                dist[neighbor]=dist[curr]+1;
                parent[neighbor]=curr;
            }
        }
    }
}



int main(){
   

    
    cin>>n>>m;
    graph.resize(n+1,list<ll>());

    while(m--){
        int s ,d;
        cin>>s>>d;
        addEdge(s,d);
    }

    dist.resize(n+10,INT_MAX);
    visited.clear();
    parent.clear();
    parent.resize(n+10);

    bfs(1,n);


    if(dist[n]==INT_MAX){
        cout<<"IMPOSSIBLE"<<endl;
    } else {
        cout<<dist[n]+1<<endl;

        vector<ll> path;

        for (ll v = n; v != -1; v = parent[v]) {
           path.push_back(v);
        }
        reverse(path.begin(), path.end());

        for(int i = 0 ; i < path.size();i++){
           cout<<path[i]<<" ";
        }

    }

    




    



    

    return 0;
}