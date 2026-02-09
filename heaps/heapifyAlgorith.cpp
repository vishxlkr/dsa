#include<bits/stdc++.h>

using namespace std;


void heapify(int i , int arr[], int n){

    while(true){
        int left = 2*i;
        int right = 2*i +1;

        int smallest = i ;

        if(left <= n and arr[left] < arr[smallest] ){
            smallest = left;
        }
        if(right <= n and arr[right] < arr[smallest]){
            smallest= right;
        }

        if(i!=smallest){
            swap(arr[i],arr[smallest]);
            i = smallest;
        } else{
            break;
        }
    }
}




int main(){

    int arr[] = {-1,10,2,14,11,1,4};

    int n = sizeof(arr) / sizeof(arr[0]) - 1;


    for(int i = n/2; i >=1 ; i--){
        heapify(i,arr,n);
    }

    for(int  i = 1 ; i<=n ; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}