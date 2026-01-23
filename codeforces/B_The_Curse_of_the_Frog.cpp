#include <bits/stdc++.h>
using namespace std;

int main(){
 ios::sync_with_stdio(0);
 cin.tie(0);

 int t;
 cin>>t;
 while(t--){

  long long n , x;
  cin>>n>>x;

  long long s=0;
  long long best= -2e18;

  for(int i=0;i<n;i++){
   long long a ,b,c;
   cin>>a>>b>>c;

   long long f=b-1;
   s+= f * a;

   long long cur = a*b - c;

   if(cur>best) best=cur;
  }

  if(s>=x){
   cout<<0<<"\n";
   continue;
  }

  long long rem = x - s;

  if(best<=0){
   cout<< -1 <<"\n";
  }
  else{
   long long need = ( rem + best - 1 ) / best;
   cout<<need<<"\n";
  }

 }

 return 0;
}
