#include<bits/stdc++.h>
using namespace std;


vector<int> nge(vector<int> &arr){
    int n = arr.size();
    vector<int> output(n,-1);
    stack<int> st;

    st.push(0);
    for(int i = 1; i < n ; i++ ){
        while(not st.empty() and arr[i] > arr[st.top()]){
            output[st.top()]= arr[i];
            st.pop();
        }

        st.push(i);
    }

    return output;
}

// keep pushing the element into the stack
// if we can pop out , then pop until its valid and update the output arr


int main(){

    vector<int> arr = {4,3,9,1,6,8,2};

    vector<int> ans = nge(arr);

    for(int i = 0 ; i < ans.size(); i++){
        cout<< arr[i] <<" ";
    }
    cout<<endl;
    for(int i = 0 ; i < ans.size(); i++){
        cout<< ans[i] <<" ";
    }

    

    return 0;
}