#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> & arr, int l ,int mid , int r){
    int an = mid-l+1;
    int bn = r-mid;
    vector<int> a(an);
    vector<int> b(bn);
    for(int i =0 ;i<an ; i++){
        a[i]= arr[l+i];
    }
    for(int j = 0 ; j<bn ; j++){
        b[j] = arr[mid+1+j];
    }
    int i =0 ; int j =0; int k = l;
    while(i<an and j<bn){
        if(a[i]<b[j]){
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

void mergesort (vector<int>&arr, int l , int r){
    if(l>=r) return ;

    int mid = l + (r-l)/2;

    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr, l ,mid , r);
}

//////////////////////////////////////////////////






void bubleSort(vector<int> & arr){
    int n = arr.size();
    for(int i =0 ; i< n-1;i++ ){
        for(int j = 0 ; j<n-1-i;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

/////////////////////////////////////////////////


void selectionSort(vector<int> & arr){

    int n = arr.size();

    for(int i = 0; i < n ;i++){
        int min_idx = i;

        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }


        if(min_idx != i){
            swap(arr[i],arr[min_idx]);
        }

    }
}

/////////////////////////////////////////////////

int partition (vector<int>&arr, int first , int last){
    int pivot = arr[last];
    int j = first;
    int i = first-1;
    int n = arr.size();

    for(j ; j<n;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }

    swap(arr[i+1],arr[last]);
    return i+1;
}

void quicksort(vector<int> &arr , int first ,int last){
    if(first>=last) return ;

    int pi = partition(arr, first,last);
    quicksort(arr,first,pi-1);
    quicksort(arr,pi+1,last);

    return ;

}



int main(){

    vector<int> v = {1,5,2,6,4,8,3,7,9};

    // mergesort(v,0,v.size()-1);

    // selectionSort(v);

    quicksort(v, 0,v.size()-1);
    
    for(int ele : v){
        cout<<ele<<" ";
    }

    return 0;
}