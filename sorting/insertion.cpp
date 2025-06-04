#include<bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> &v, int n) {
    for (int i = 1; i < n; i++) {
        int current_element = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > current_element) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = current_element;
    }
}


int main(){

    int n; cin>>n;
    vector<int> v(n);

    // take intput

    insertionSort(v,n);

    // output

    

    return 0;
}