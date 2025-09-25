#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll f(string & s){
    int l = 0;
    int r = 0;
    int n = s.size();

    ll maxlen = 0;
    ll currlen= 0;
    
    while(r<n){

        if(s[l]==s[r]){
            currlen++;
            r++;
        }else{
            currlen=1;
            l=r;
            r++;
        }

        if(currlen>maxlen) maxlen = currlen;
    }

    return maxlen;
}


int main(){

    string s; 
    cin>>s;

    cout<<f(s);

    
    

    return 0;
}