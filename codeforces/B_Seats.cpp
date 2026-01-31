#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
      cin >>t;

    while( t-- ){
         int  n;
        cin  >> n;
        string  s;
        cin>> s;



        vector<int>    pos;
        for( int i=0; i<n; i++ ) {
             if( s[i] == '1' )
                pos.push_back(i);
        }

        if(   pos.empty() ){


             cout   << (n + 2) / 3 << endl;



               continue;
        }

        int ans   = pos.size();

        
        int L =   pos[0];
        ans += (L + 1) / 3;

        int R   =   n   - 1 -   pos.back();
        ans  +=   ( R  +  1  ) /  3 ;


        for( size_t k   = 0 ;  k < pos.size() - 1 ;   k++ ){
            int  gap =  pos[k+1]   - pos[k] - 1;
            ans    +=  gap   / 3;
        }

        cout<<    ans   <<  "\n";
    }

    return   0;
}