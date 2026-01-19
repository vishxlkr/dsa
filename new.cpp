#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src;
    int des;
    int wt;
};

bool cmp (Edge e1 , Edge e2){
    return e1.wt < e2.wt;
}

//find 
int find(vector<int> &parent , int x){
    return parent[x]= (parent[x]== x)? parent[x] : find(parent, parent[x]);
}

// union
void Union(vector<int>&parent , vector<int>&rank , int x , int y){
    int a = find(parent, x);
    int b = find(parent , y);

    if(a==b) return ;
    if(rank[a] >= rank[b]) {
        rank[a]++;
        parent[b]=a;
    } else {
        rank[b]++;
        parent[a]=b;
    }
}



int f(vector<Edge> &v ,  int n , int e ){
    unordered_set<int> visited;
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    for(int i=0; i <= n ; i++){
        parent[i]=i;
    }

    sort(v.begin(), v.end(), cmp);

    int ans= 0;
    int edgecount = 0;
    int i =0;

    while(edgecount < n-1 and i < v.size()){
        auto curr = v[i];
        int a = find(parent , curr.src);
        int b = find(parent , curr.des);

        if(a!=b){
            ans= ans + curr.wt;
            Union(parent, rank, a,b);
        }

        i++;
    }

    return ans;


}




int main(){

    int n , e;

    cin>>n>>e;

    vector<Edge> v(e);

    for(int i = 0; i < e ; i++){
        cin>>v[i].src>>v[i].des>>v[i].wt;
    }

    cout<<f(v,n,e);

    

    return 0;
}