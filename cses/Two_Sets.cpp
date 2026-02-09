#include<bits/stdc++.h>

using namespace std;
#define ll long long




int main(){

    int n ;
    cin>>n;

    ll sum = 1LL* n*(n+1)/2;

    if(sum % 2 != 0) {
        cout<<"NO";
        return 0;
    }

    ll target = sum/2;

    vector<int> a;
    vector<int> b;
    
    for(int i = n ; i >=1; i--){
        if(target >= i){
            target=target-i;
            a.push_back(i);

        } else {
            b.push_back(i);
        }
    }

    cout<<"YES"<<endl;

    cout<<a.size()<<endl;
    for(int i = 0 ; i < a.size();i++){
        cout<<a[i]<<" ";
    }

    cout<<endl;

    cout<<b.size()<<endl;
    for(int i = 0 ; i < b.size();i++){
        cout<<b[i]<<" ";
    }

    

    

    return 0;
}