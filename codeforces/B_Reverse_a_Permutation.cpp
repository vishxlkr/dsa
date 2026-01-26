#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);


    cin.tie(NULL);

    int  t;
    cin >>  t;



    while (t--){
        int  n;
        cin  >> n;
        vector<int>    p(n);
        for(int i =    0; i < n; i++) cin >> p[i];

        vector<int>  suf(n);

        suf [n-1]  =   p[n-1];

        for  (int i = n-2; i >= 0; i--)
            suf[i] =   max(p[i], suf[i+1]);

        int  l = -1,    r = -1;


        

        for  (int i = 0;   i < n; i++){

            if(p[i] !=   suf[i]){


                l = i;
                for(int j =   n-1; j >   i; j--){
                    if(p[j] ==   suf[i]){
                        r   = j;
                          break;
                    }
                } 
                 break;
            }
        }

        if( l != -1){
            reverse( p.begin()  +  l,  p.begin()  + r + 1);
        }

        for( int x :  p) cout  << x << " ";
          cout  <<   "\n";
    }
}
