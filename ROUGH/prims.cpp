#include<bits/stdc++.h>
#define pp pair<int,int>
#define ll long long int

using namespace std;

vector<list<pair<int,int>>> graph;

int v;

void addEdge(int s ,int d ,int wt, bool bidir= true){
    graph[s].push_back({d,wt});
    if(bidir){
        graph[d].push_back({s,wt});
    }
}


ll prims(int src ,int n){
    vector<int> parent (n+1);
    unordered_map<int,int> mp;
    for(int i = 1 ; i <n+1; i++){
        mp[i] =  INT_MAX;
    }
    unordered_set<int> visited;
    priority_queue<pp, vector<pp> , greater<pp>> pq;

    
    pq.push({0,src});

    int totalCount = 0 ; 
    int ans = 0;
    while(totalCount <n and not pq.empty()){
        pp curr = pq.top();
        pq.pop();
        if(visited.count(curr.second)){
            continue;
        }

        visited.insert(curr.second);    // whenever we are popping element , we are marking it visited
        ans = ans + curr.first;
        totalCount++;


        for(auto neighbor : graph[curr.second]){
            if(!visited.count(neighbor.first) and mp[neighbor.first] > neighbor.second){
                pq.push({neighbor.second,neighbor.first});
                mp[neighbor.first]= neighbor.second;
                parent[neighbor.first] = curr.second;

            }
        }

    }

    return ans;


}





int main(){

    cin>>v;     
    graph.resize(v, list<pp> ());
;
    int e; cin>>e;
    while(e--){
        int s, d, wt;
        cin>>s>>d>>wt;

        addEdge(s,d,wt);
    }

    int src;
    cin>>src;

    

   
    
    return 0;
}