#include<bits/stdc++.h>

using namespace std;

void selectionSort(vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        
        // this loop to find the min idx
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }

        // if min idx element is not at its correct position then swap
        if (min_idx != i) {
            swap(v[i], v[min_idx]);
        }
    }
}




int main(){

    vector<int> v ={6,2,1,5,3,4,9,7,8};
    
    selectionSort(v,v.size());

    for(int ele : v){
        cout<<ele<<" ";
    }
    

    return 0;
}