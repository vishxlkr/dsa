#include<bits/stdc++.h>

using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;




void addEdge(int s , int d , bool bidir = true){
    graph[s].push_back(d);
    if(bidir){
        graph[d].push_back(s);
    }
}

void display(){
    for(int i =0 ; i< graph.size();i++){\
        cout<<i<<"->";
        for(auto el:graph[i]){
            cout<<el<<" ";
        } cout<<endl;
    }
}






int main(){

    int v ; cin>>v;
    graph.resize(v,list<int>());

    int e;cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        addEdge(s,d);
    }
    cout<<"output"<<endl;
    display();

    return 0;
}