#include<bits/stdc++.h>

using namespace std;


int find(vector<int> &parent, int x){

    return parent[x]= (parent[x]==x)? x : find(parent , parent[x]);
}

void Union(vector<int> & parent , vector<int> & rank , int x , int y){
    int a = find(parent ,x);
    int b = find(parent ,y);

    if(a==b) return ;
    if(rank[a]>=rank[b]){
        rank[a]++;
        parent[b]=a;
    } else {
        rank[b]++;
        parent[a]=b;
    }
}






int main(){

    int v,e;
    cin>>v>>e;

    vector<int> parent (v+1);
    vector<int> rank (v+1,0);

    for(int i= 0; i< v+1;i++){
        parent[i]=i;
    }

    while(e--){
        string s;
        cin>>s;

        if(s=="union"){
            int x, y;
            cin>>x>>y;
            Union(parent, rank , x, y);
        } else {
            int x ;
            cin>> x;
            find (parent  , x);
        }
    }




    return 0;
}