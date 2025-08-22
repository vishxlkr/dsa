#include<bits/stdc++.h>

using namespace std;

#define ll long long int




int main(){

    int n;      // no of machines 
    ll t ;      //no of products to make
    cin>>n>>t;

    vector<ll> k(n);
    for(int i =  0 ; i < n;i++){
        cin>>k[i];
    }

    // binary search bounday
    ll low =1 ;
    ll high = 1e18;    // max possible time (big number) ->ll

    ll ans = high;

    while(low<=high){
        ll mid = low + (high-low)/2;

        ll product = 0;
        for(int i = 0 ; i<n;i++){
            product = product + mid/k[i];
            if(product>=t) break;           // here the product >= t already
        }

        if(product >= t){
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
        


    }

    cout<<ans<<endl;




    
    

    return 0;
}