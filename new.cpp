#include<bits/stdc++.h>
using namespace std;



 int mySqrt(int x) {
        int low = 0, high = x;
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(mid <= x / mid) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }


int main(){

    cout<<mySqrt(8);



    

    return 0;
}