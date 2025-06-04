#include<bits/stdc++.h>

using namespace std;

bool f(vector<int> v, int i, int target){
    if(i==v.size()) return false;
    
    return (v[i]==target || f(v,i+1,target));
}


int main(){

    vector<int> v = {5,3,2,1,1,6,7,3};
    int target = 7;

    cout<<f(v,0 , target);

    return 0;
}