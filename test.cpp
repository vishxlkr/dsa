#include<bits/stdc++.h>
using namespace std;


int partition(vector<int> & v , int first ,int last){
    int j = first ;
    int i = first-1;

    int pivot = v[last];

    for(j ; j<last ; j++){
        if(v[j] < pivot){
            i++;
            swap(v[i],v[j]);
        }
    }

    swap(v[i+1], v[last]);
    return i+1;
}

void quicksort (vector<int> & v , int first , int last){
    if(first > last ) return ;

    int pi = partition(v, first , last);

    quicksort(v,first , pi-1);
    quicksort(v,pi+1 , last);
}


int main(){

    vector<int> v = {4,6,9,8,3,1,0,5};
    quicksort(v,0,v.size()-1);
    for(int x : v){
        cout<<x <<" ";
    }

    return 0;
}



git quickgit quickgit quickgit quick