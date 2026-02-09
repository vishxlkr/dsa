#include<bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &v, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                flag = true;
            }
        }
        if (!flag) break;  
    }
}


    
int main(){
    // int n ; cin>>n ;
    vector<int> v = {3,4,7,4,2,1,5,3,54,2};

    // take input in vector

    // bubbleSort(v,n);

    sort(v.begin(),v.end());

    for(auto ele: v){
        cout<<ele<<" ";
    }

    //  output of vector

}

