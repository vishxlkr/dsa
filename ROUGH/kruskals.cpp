#include<bits/stdc++.h>
#define ll long long

using namespace std;

int find (vector<int> &parent , int x){
    return parent[x] = (parent[x]==x)? x : find(parent , parent[x]);
}

void Union(vector<int> & parent , vector<int> & rank , int x , int y){
    int a = find(parent , x);
    int b = find(parent , y);

    if(a==b) return;

    if(rank[a]>= rank[b]){
        rank[a]++;
        parent[b] = a;
    } else {
        rank[b]++;
        parent[a]=b;
    }
}

struct Edge{
    int src;
    int des;
    int wt;
};

bool cmp (Edge e1, Edge e2){
    return e1.wt < e2.wt;
}

ll kruskals (vector<Edge>input , int n ){
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i = 0 ; i<=n ; i++){
        parent[i]=i;
    }

    sort(input.begin(),input.end(),cmp);
    int edgecount = 0 ; 
    ll ans = 0 ;
    int i =0;

    while(edgecount < n-1 and i < input.size()){
        Edge curr = input[i];
        int srcParent = find(parent , curr.src);
        int desParent = find(parent , curr.des);
        
        if(srcParent != desParent){
            Union(parent , rank , srcParent, desParent);
            ans+= curr.wt;
            edgecount++;
        }
        i++;
    }

    return ans;

}


int main(){

    

    return 0;
}