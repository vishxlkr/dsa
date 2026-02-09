#include<bits/stdc++.h>

using namespace std;

int n , m ;
vector<list<int>> graph;
unordered_set<int> visited;
int countt;

void addEdge(int s ,int d , bool bidir = true){
    graph[s].push_back(d);
    if(bidir) graph[d].push_back(s);
}

// void dfs(int curr){
//     visited.insert(curr);
//     for(auto neighbor : graph[curr]){
//         if(not visited.count(neighbor)){
//             dfs(neighbor);
//         }
//     }
// }


// int connectedComponent(){

//     for(int i = 1 ; i < n+1 ; i++){
//         if(not visited.count(i)){
//             countt++;
//             dfs(i);
//         }
//     }

//     return countt;

// }

int find(vector<int> & parent , int x){
    return parent[x]= (parent[x]==x) ? x : find(parent, parent[x]);
}

void Union (vector<int>&parent , vector<int>&rank , int a ,int b){
    a = find(parent , a);
    b = find(parent , b);

    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b]=a;
    } else{
        rank[b]++;
        parent[a]=b;
    }
}




int main(){

    cin>>n>>m;

    // graph.resize(n+1, list<int>());

    // while(m--){
    //     int s, d;
    //     cin>>s>>d;
    //     addEdge(s,d);
    // }
    // countt=0;
    // int ans = connectedComponent();
    // cout<<ans;

    vector<int>parent(n+1);
    vector<int> rank(n+1,0);

    for(int i = 1 ; i <=n ; i++ ){
        parent[i]=i;
    }

    while(m--){
        int u, v;
        cin>>u>>v;
        Union(parent,rank,u,v);
    }

    unordered_set<int> nodes;
    for(int i = 1 ; i <=n;i++ ){
        nodes.insert(find(parent,i));
    }

    // cout<<"{";
    // for(auto el : nodes ){
        
    //     cout<<el<<" ";
    // }cout<<"}";

    int newRoads = nodes.size()-1;

    
    cout<< newRoads <<endl;

    queue<int> qu;
    for(auto el : nodes){
        qu.push(el);
    }

    while(newRoads){
        int first= qu.front(); qu.pop();
        int second= qu.front(); qu.pop();

        Union(parent, rank , first, second);
        cout<<first<<" "<<second<<endl;
        if(rank[first]>=rank[second]) qu.push(first);
        else  qu.push(parent[first]);
        newRoads--;
    }

    


    return 0;
}