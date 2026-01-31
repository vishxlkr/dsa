#include <bits/stdc++.h>
using namespace std;

int par[200005];

int find(int x){
   if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    if(rootX != rootY){
         par[rootX] = rootY;
    }
}

bool check(int k, int n, const vector<int>& a, const vector<int>& b, int min_idx, int max_idx){
    for(int i=0; i<n; i++) par[i] = i;

     for(int i=0; i<n; i++){
        if( abs(a[i] - a[min_idx]) >= k ){
            unite(i, min_idx);
        }
        if( abs(a[i] - a[max_idx]) >= k ){
             unite(i, max_idx);
        }
    }
    
    // Check if valid
    // We group indices by component
    vector< vector<int> > comps(n);
    for(int i=0; i<n; i++){
        comps[ find(i) ].push_back(i);
    }
    
    for(int i=0; i<n; i++){
        if( comps[i].empty() ) continue;
        
        vector<int> valA;
        vector<int> valB;

        for( int idx : comps[i] ){
            valA.push_back( a[idx] );
             valB.push_back( b[idx] );
        }
        
        sort(valA.begin(), valA.end());
        sort(valB.begin(), valB.end());
        
        if( valA != valB ) return false;
    }
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int    t;

    cin >>   t;


    while(t--){
        int   n;

        cin  >>   n;
        vector   <int>  a(n);
        int  mn  =  2e9 ,  mx = -1;
        int   min_idx =  0,   max_idx = 0;

        for(int  i=0;  i  < n; i++){

            cin  >> a[i];


             if(a[i]  <    mn){

                  mn    = a[i];
                min_idx   = i;

            }
            if(a[i] >   mx){

                  mx =  a[i];

                max_idx   = i;

            }
        }

        vector<int>   b   = a  ;
        sort(  b.begin()   ,   b.end());

        if( a  == b   ){
            cout   <<   -1 << "\n";
            continue    ;
        }

        
        int low =   1,   high   = 1000000000;
        int ans =    0;

        while( low   <=    high ){
             int mid   =   low   + (high - low)/2;
             if( check(mid,   n, a, b, min_idx, max_idx) ){
                ans   =    mid;
                low   =      mid + 1;
             }
             else{
                  high =   mid - 1;
             }
        }
        
        cout    <<   ans   <<  endl;

    }
    return    0;
}