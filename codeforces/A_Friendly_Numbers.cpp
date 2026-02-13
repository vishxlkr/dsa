#include <bits/stdc++.h>
using namespace std;

long long digitSum(long long value) {
    long long total = 0;



     while  (value  > 0) {


        total  +=  value % 10;



        value =   value/ 10;





    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL)  ;




    int  testCount  ;


    cin >>   testCount;

    while   (testCount--) {


        long   long   x;


        cin >>  x;



        int friendlyCount = 0;

        for (int guessSum = 1; guessSum <= 90; guessSum++) {
            long long   candidateNumber = x + guessSum;

            if  (digitSum(candidateNumber) == guessSum)
                friendlyCount++;
        }

        cout <<   friendlyCount <<   "\n";


    }


    
     return 0;
}
