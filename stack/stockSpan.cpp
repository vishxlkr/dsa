#include<bits/stdc++.h>
using namespace std;



vector<int> pge (vector<int> &arr){
    int n = arr.size();
    vector<int> output(n,-1);
    stack<int> st;


    st.push(n-1);
    for(int i = n-2; i >=0 ;i--){
        while(not st.empty() and arr[i] > arr[st.top()]){
            output[st.top()]=i;
            st.pop();
        }

        st.push(i);
    }

    return output;
}

// here i found the next greater element from behind 
// and stored the index of next greater element and not the element itself
// and the end, print the difference


int main(){

    vector<int> arr = {40,30,90,10,60,80,20};

    vector<int> ans = pge(arr);

    for(int i = 0 ; i < ans.size(); i++){
        cout<< arr[i] <<" ";
    }
    cout<<endl;
    for(int i = 0 ; i < ans.size(); i++){
        cout<< i- ans[i] <<" ";
    }

    

    return 0;
}