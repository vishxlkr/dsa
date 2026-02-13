#include <iostream>
#include <vector>


#include <algorithm>

using  namespace std;

void solve(){
    int n  ;
    cin>>n;

    vector<int>  p(n);



    vector<int>   pos(n+1);


    for(int i=0;  i<n;i++){


        cin>>  p[i];


        pos [p[i]] = i;


    }

    vector  < int> a(n);


    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> b;


    if(n>0  )  b.push_back(a[0]);



    for(int i= 1  ;i<n ;  i++){



        if(a[i] !=a[i-1])



            b.push_back(a[i])  ;
    }

    bool possible=true;

    for(int i=0;   i+1   < (int)b.size(); i++){

        int u= b[i];


        int v =b[i+1];


        if(pos[u] > pos[v]){

             possible= false;

            break;
        }
    }

    if(possible)  cout<<"YES"<<endl;


    else cout<<"NO"<<endl;
}

int main(){
    int t;


    cin>>t;


    while(t--) solve();



    
    return 0;
}
