#include <iostream>
#include <vector>

using namespace std;

void solve(){

    int n;


    cin>>n;



    vector<int>   a(n+1);

    for(int   i=1;i<=n  ;++i){
        cin>> a[i];
    }

    long long   ans = 0;

    for(int x=1;   x*x < n; ++x){

        for(int j=1;   j<=n; ++j){

            

            if (a[j] <  x)   continue;

            long  long diff = (long long)a[j]*x;

            if(diff  >= j) continue;

            int i = j  - (int)diff;

            if(a[i]  == x){
                ans++ ;
            }
        }

        for(int i=1; i<=n; ++i){

            if(a[i] <= x) continue ;

            long long diff = 
            (long long)a[i]*x ;

            if(i + diff > n) continue;

            int j = i + (int)diff;



            if(a[j] == x){


                ans++;
            }
        }
    }

    cout<<ans<<endl;
}

int main(){

    ios_base::sync_with_stdio(false)  ;


    cin.tie(NULL)  ;


    int t  ;


    cin>>t;

    while(t--){


        solve();
    }

    return 0;
}
