#include<bits/stdc++.h>

using namespace std;

class MinHeap{
    public: 

    int arr[];
    int idx;

    MinHeap(){
        idx = 1;
    }

    int top(){
        return arr[1];
    }

    int push(int x){
        arr[idx]= x;
        int i = idx;
        idx++;

        //find parent and compare
        while(i!=1){
            int parent = i/2;
            if(arr[i] < arr[parent]) {
                swap(arr[i],arr[parent]);
            } else {
                break;
            }
            i = parent;
        }
    }

    int size(){
        return idx-1;
    }

    int pop(){
        idx
    }




};


int main(){

    

    return 0;
}