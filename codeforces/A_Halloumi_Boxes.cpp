#include<bits/stdc++.h>

using namespace std;


bool checkSorted(vector<int> &v){
    int n = v.size();
    for(int i = 0 ; i < n-1; i++){
        if(v[i]>v[i+1]) return false;
    }
    return true;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n , k;
        cin>>n>>k;
        vector<int> v(n); 
        for(int i = 0 ; i <n;i++){
            cin>>v[i];
        }

        if(k>=2) cout<<"YES"<<endl;

        if(k==1){
            bool check = checkSorted(v);
            if(check) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

        if(k<1) cout<<"NO";
    }

    return 0;
}