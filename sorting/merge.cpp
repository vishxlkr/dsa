#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>&v, int l , int mid , int r){
    
    int an = mid - l + 1;
    int bn = r - mid;

    vector<int> a(an);
    vector<int> b(bn);

    for(int i = 0 ; i < an ; i++){
        a[i] = v[l+i];
    }

    for(int j = 0 ; j< bn ; j++){
        b[j] = v[mid+1+j];
    }

    int i = 0  , j = 0  , k = l;

    while (i < an and j < bn){
        if(a[i]< b[j]){
            v[k++] = a[i++];
        } else {
            v[k++] = b[j++];
        }
    }
        while (i < an ){
            v[k++] = a[i++];
        }
        while (j<bn){
            v[k++] = b[j++];
        }
}

void mergesort(vector<int>& v, int l , int r){
    if(l>=r) return ;                               // if here we dont use = then it will infintely

    int mid = (l+r)/2;

    mergesort(v,l,mid);
    mergesort(v,mid+1,r);
    merge(v,l,mid,r);
}


int main(){

    vector<int> v = {2,4,7,9,1,3,5,8};

    int n = v.size()-1;

    mergesort(v,0,n);

    for(auto x : v){
        cout<<x<<" ";
    }

    return 0;
}