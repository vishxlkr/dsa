#include<bits/stdc++.h>

using namespace std;

bool cmp (int a, int b){
    return a>b;
}

int main(){

    vector<int> horizontal = {4,1,2};                // horizontal cut  x
    vector<int> vertical = {2,1,3,1,4};            // vertical cuts     y

    sort(horizontal.begin(), horizontal.end(),cmp);
    sort(vertical.begin(), vertical.end(),cmp);

    int v = 0;      // to iterate on x
    int h = 0;      // to iterate on y

    int hPieces = 1;
    int vPieces = 1;

    int total = 0 ;

    while(v< horizontal.size() and h <vertical.size()){
        if(horizontal[v] >= vertical[h]){
            total = total + horizontal[v]*vPieces;
            hPieces++;
            v++;
        } else if(horizontal[v] < vertical[h]){
            total = total + vertical[h]*hPieces;
            vPieces++;
            h++;
        }
    }
    while(v<horizontal.size() ){
        total = total + horizontal[v]*vPieces;
            hPieces++;
            v++;
    }
    while (h <vertical.size()){
        total = total + vertical[h]*hPieces;
            vPieces++;
            h++;
    }
    
    cout<<total;
    
    return 0;
}