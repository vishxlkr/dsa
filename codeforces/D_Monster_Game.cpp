#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);


    cin.tie(NULL);

    int t;



    cin >> t;





    while(t--){
        int n;



        cin >> n;




        vector<long long>  a(n);



        for(int i=0;i<n;i++)    cin >> a[i];

        vector<long long>   b(n);


        for(int i=0;i<n;i++)   cin >> b[i];

        sort(a.begin(), a.end(),    greater<long long>());





        vector<long long>  prefB(n+1,0);
        for(int i=0;i<n;  i++){
            prefB[i+1] =   prefB[i] + b[i];
        }

        long long   ans = 0;




        for(int   i=1;i<=n;i++){
            long   long x = a[i-1];  
            long    long cnt = i;   

            
            int k =    upper_bound(prefB.begin(), prefB.end(), cnt) - prefB.begin() - 1;

            ans =    max(ans, x * k);
        }

        cout <<   ans << "\n";
    }
}
