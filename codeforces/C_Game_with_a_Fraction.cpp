#include <iostream>
using namespace std;

void solve() {

    long long p ,  q;


    cin>>p>> q;

    if(  3*p  == 2*q ){


         cout<<"Bob"<<endl;


         return;
    }

    long long  k = q - p;

    if(k >  0)
    {
        if(  2*k <= p && 3*k  <= q )
        { 

            cout<< "Bob"<<endl;


             return;
        }
    }

    cout<<"Alice" <<endl;
}

int main(){

    ios_base::sync_with_stdio(false);


    cin.tie(NULL);

    int t;


    cin>>t;



    while(t--){
        solve();
    }


    

    return 0;
}
