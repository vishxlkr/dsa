#include<bits/stdc++.h>

using namespace std;
#define pp pair<int,int> 
#define ll long long int

vector<list<pp>> graph;

void addEdge(int s, int d, int wt , bool bidir = true){
    graph[s].push_back({d,wt});
    if (bidir) graph[d].push_back({s,wt});
}


ll prims (int src, int n){
    priority_queue<pp, vector<pp>, greater<pp>> pq;         // wt , node
    unordered_set<int> visited;                     // node
    unordered_map<int, int> mp;                 // node    , distance
    vector<int> parent(n+1);                    // node , parent
    for(int i = 1; i < n+1 ; i++){
        mp[i]=INT_MAX;
    }
    mp[src]=0;
    pq.push({0,src});

    int totalcount = 0; // n-1
    ll ans = 0;             // final output

    while (totalcount <n and !pq.empty()){
        pp curr = pq.top();
        pq.pop();
        

        if(visited.count(curr.second)) {
            // pq.pop();
            continue;
        }

        // if not visited
        visited.insert(curr.second);
        totalcount++;
        ans = ans + curr.first;
        // pq.pop();

        for(auto neighbor : graph[curr.second]){
            if(not visited.count(neighbor.first) and neighbor.second < mp[neighbor.first]){
                pq.push({neighbor.second,neighbor.first});
                mp[neighbor.first] = neighbor.second;
                parent[neighbor.first] = curr.second;
            }
        }
    }
    return ans;

}
