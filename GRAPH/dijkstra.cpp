#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

vector<list<pp>> graph;


void addEdge(int s , int d, int wt , bool bidir = true){
    graph[s].push_back({d,wt});
    if(bidir) graph[d].push_back({s,wt});
}


unordered_map<int,int> dijkstra (int n , int src, int des){

    unordered_map<int,int> mp;
    unordered_set<int> visited;
    priority_queue<pp, vector<pp> , greater<pp> > pq;
    vector<int> parent(n+1);

    for(int i = 0 ; i < n; i++){
        mp[i]= INT_MAX;
    }



    pq.push({0,src})
    mp[src]=0;

    while(not pq.empty()){
        ()
    }


}


int main(){

    int n ; cin>>n;             // n -> no of vertices 
    graph.resize(n,list<pp> ());

    int e; cin>>e;
    while(e--){
        int s, d, wt;
        cin>>s>>d>>wt;
        addEdge(s,d,wt);
    }


    

    return 0;
}