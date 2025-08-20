#include<bits/stdc++.h>

using namespace std;

#define ll long long 


int main(){

    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n; cin>>n;
    
    set<ll> visited;
    while(n--){
        ll num ; 
        cin>>num;
        visited.insert(num);
    }

    cout<<visited.size();

    return 0;
}