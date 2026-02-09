#include<bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int first , int last){
    int pivot = arr[last];
    int i = first - 1; 
    int j = first;


    for(j ; j < last ; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[last]);
    return i+1;
}






void quicksort (vector<int> &arr, int first , int last){
    if(first >= last ) return ;

    int pi = partition(arr, first, last);

    quicksort(arr, first , pi -1);
    quicksort(arr, pi +1, last);

}


int main(){

    vector<int> arr = {1,7,3,8,4,6,2,10,44,21};
    
    quicksort(arr, 0 , arr.size()-1);

    for(auto ele: arr){
        cout<<ele<<" ";
    }

    

    return 0;
}