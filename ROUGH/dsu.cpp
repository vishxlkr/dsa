#include<bits/stdc++.h>

using namespace std;

int find(vector<int> & parent , int  x){
    return parent[x] = (parent[x]==x)? x : find(parent, parent[x]);
}


void Union(vector<int> &parent , vector<int> &rank , int x , int y){
    int a = find(parent , x);
    int b = find(parent , y);

    if(a==b) return ;

    if(rank[a]>=rank[b]){
        rank[a]++;
        parent[b]=a;
    } else {
        rank[b]++;
        parent[a]=b;
    }

    return;

}


int main(){

    int n , m;
    cin>>n>> m;
    // n - no of elements , m - no of queries

    vector<int> parent (n+1);
    vector<int> rank(n+1, 0);

    while(m--){
        int str; 
        cin>>str;
        if(str=="union"){
            int a, b;
            cin>>a>>b;
            Union(parent ,  rank , a,b);
        } else {
            int x;
            find(parent , x);
        }
    }

    return 0;
}