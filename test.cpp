#include<bits/stdc++.h>
using namespace std;


// int partition(vector<int> & v , int first ,int last){
//     int j = first ;
//     int i = first-1;

//     int pivot = v[last];

//     for(j ; j<last ; j++){
//         if(v[j] < pivot){
//             i++;
//             swap(v[i],v[j]);
//         }
//     }

//     swap(v[i+1], v[last]);
//     return i+1;
// }

// void quicksort (vector<int> & v , int first , int last){
//     if(first > last ) return ;

//     int pi = partition(v, first , last);

//     quicksort(v,first , pi-1);
//     quicksort(v,pi+1 , last);
// }


void merge(vector<int>&arr, int l , int mid , int r){
    int an = mid - l +1;
    int bn = r - mid;

    vector<int> a(an);
    vector<int> b(bn);

    for(int i = 0 ; i < an; i++){
        a[i] = arr[l+i];
    }

    for(int j = 0; j < bn ; j++){
        b[j] = arr[mid + 1 + j];
    }

    
    int i = 0; 
    int j = 0; 
    int k = l;

    while(i < an and j < bn){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        } else {
            arr[k++] = b[j++];
        }
    }

    while(i<an){
        arr[k++] = a[i++];
    }

    while(j<bn){
        arr[k++] = b[j++];
    }
}



void mergesort (vector<int> &arr, int l , int r){
    if(l>=r) return ;

    int mid = (l+r)/2;

    mergesort(arr , l , mid);
    mergesort(arr, mid+1, r);

    merge(arr, l , mid , r);
}

int partition (vector<int> & arr, int first , int last){
    int pivot = arr[last];

    int i = first -1;
    int j = first;

    for( j ; j < last ; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);

        }
    }

    swap(arr[i+1], arr[last]);

    return i+1;
}


void quicksort (vector<int> & arr, int first  , int  last){

    if(first >= last ) return ;

    int pi = partition(arr, first , last);

    quicksort(arr, first , pi-1);
    quicksort(arr, pi + 1 , last);


}





int main(){

    vector<int> v = {4,6,9,8,3,1,0,5};
    quicksort(v,0,v.size()-1);
    for(int x : v){
        cout<<x <<" ";
    }

    return 0;
}



