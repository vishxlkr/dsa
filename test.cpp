#include<bits/stdc++.h>
using namespace std;


    int f(int n) {
        int m = n;
        int reverse = 0;

        while(m!=0){
            reverse = reverse*10 + m%10;
            m= m/10;
            
        }
        cout<<reverse<<endl;

        cout<<n-reverse<<endl;

        

        // return 10;
    }



int main(){

    cout<<f(25);

    return 0;
}

git quickgit quickgit quickgit quickgit quickgit quickgit quickgit quickgit quickgit quickgit _QUERY_MSVC_PRINTF_QUIRKS
git quickgit quick