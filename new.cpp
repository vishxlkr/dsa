#include<bits/stdc++.h>
using namespace std;

#define pp pair<int,int>

vector<list<pp>> graph;
int v;

void addEdge(int s, int d, int wt, bool bidir = true){
    graph[s].push_back({d,wt});
    if(bidir) graph[d].push_back({s,wt});
}

int f(int n , int e){

    priority_queue<int, vector<int> , greater<int> > pq;
    unordered_set<int> visited;
    

}

int main(){

    cin>>v;
    int e;
    cin>>e;
    while(e--){
        int s, d, wt;
        cin>>s>>d>>wt;
        addEdge(s,d,wt);
    }

    cout<<f(v,e);
    

    return 0;
}