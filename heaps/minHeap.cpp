#include<bits/stdc++.h>

using namespace std;

class minHeap{
    public:

    vector<int> arr;
    int idx ;

    minHeap(){
        arr.resize(50);
        idx = 1;
    }

    int top(){
        return arr[1];
    }

    int push(int x){
        arr[idx]= x;
        int i = idx;
        idx++;

        while (i!=1){
            int parent = i/2;
            if(arr[i]<arr[parent]){
                swap(arr[i],arr[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    int pop(){
        idx--;
        swap(arr[1],arr[idx]);
        

        int i = 1;
        
        while(true){
            int left = 2*i ;
            int right = 2*i+1;

            int smallest = i;

            if(left < idx and arr[left]<arr[smallest]){
                smallest = left;
            }
            if(right < idx and arr[right]<arr[smallest]){
                smallest = right;
            }

            if(smallest != i){
                swap(arr[smallest], arr[i]);
                i = smallest;
            } else {
                break;
            }
        }
    }

    
   




    void display(){
        for(int i = 1 ; i<idx;i++){
            cout<<arr[i]<<" ";
        }
    }
};


int main(){
    minHeap pq;
    pq.push(100);
    pq.push(18);
    pq.push(12);
    pq.push(4);
    pq.push(3);
    pq.push(10);




    pq.display(); cout<<endl;
    pq.pop();
    pq.display(); cout<<endl;
    pq.pop();
    pq.display(); cout<<endl;
    pq.pop();
    pq.display(); cout<<endl;
    pq.pop();
    pq.display(); cout<<endl;
    










    
    

    return 0;
}