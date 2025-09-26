#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int> arr = {2,-3,4,4,-7,-1,4,-2,6};
    int k = 3;   //  3 3 3 3 7  7 7  1 2 
    int n = arr.size();

    vector<int> ans(n-k+1); 
    int p=-1;


    // for first window
    for(int i = 0 ;i<k;i++){
        if(arr[i]<0){
            p=i;
            break;
        }
    }
    if(p==-1) {
        ans[0]=1;
    } else {
        ans[0]=arr[p];
    }



    // for other windows
    int i = 1;
    int j = k;
    
    while(j<n ){
        if(p>= i){
            ans[i]=arr[p];
        } else{
            //find first negative number again
            for(int x = i; x<= j;x++){
                if(arr[x]<0){
                    p=x;    
                    ans[i]=arr[p];
                    break;
                }
            }
            if(p<i) ans[i]=1; // if no negative no is present
        }
        i++;
        j++;
    }

    for(int i = 0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i = 0 ; i<n+k-1 ;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}