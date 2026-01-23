#include <bits/stdc++.h>
using namespace std;

int main(){
 ios::sync_with_stdio(0);
 cin.tie(0);

 int  t;
 cin>>t;



 while(t--){
  int  n,h,l;
  cin>>n>>h>>l;

  int a= min (h,l),b=max(h,l);


  int x=0,y=0;

  for(int  i=0;i<n;i++){
   int v ;
   cin>>v;
   if (v<=a) x++;
   else  if(v<=b) y++;
  }

  int ans=0;

  int k= min(x,y);

  ans+= k;
  x-=k;

  ans += x/2;

  cout <<ans<<"\n";
 }

 return 0;
}
