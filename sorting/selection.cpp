#include<bits/stdc++.h>

using namespace std;

void selectionSort(vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            swap(v[i], v[min_idx]);
        }
    }
}




int main(){

    

    return 0;
}