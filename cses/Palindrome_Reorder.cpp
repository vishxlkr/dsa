#include<bits/stdc++.h>

using namespace std;




int main(){

    string s; 
    cin>>s;

    unordered_map<char,int> mp;

    for(int i = 0 ; i < s.size();i++){
        mp[s[i]]++;
    }

    string firsthalf = "";
    string middle = "";
    string lasthalf = "";

    int oddCount = 0; 
    char oddchar = 0;

    
    for(auto ele: mp){
        if( ele.second %2 != 0 ) {
            oddCount++ ;
            oddchar = ele.first;
        }
    }

    if(oddCount >= 2) {
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }

    for(auto ele: mp){

        int half  = ele.second/2;

        while(half){
            firsthalf += ele.first;
            lasthalf += ele.first;
            half--;
        }

    }

    if(oddCount==1){
        middle += oddchar;
    }

    reverse(lasthalf.begin(),lasthalf.end());

    cout<<firsthalf + middle + lasthalf;




    

    return 0;
}