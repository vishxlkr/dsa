#include <bits/stdc++.h>
using namespace std;

int maximumLength(int input1, int input2[]) {
    if (input1 == 0) return 0;
    if (input1 == 1) return 1;

    int inc = 1, dec = 1;          // current streaks
    int maxInc = 1, maxDec = 1;    // best so far

    for (int i = 1; i < input1; i++) {
        if (input2[i] > input2[i-1]) {
            inc++;
        } else {
            inc = 1;
        }

        if (input2[i] < input2[i-1]) {
            dec++;
        } else {
            dec = 1;
        }

        maxInc = max(maxInc, inc);
        maxDec = max(maxDec, dec);
    }

    return max(maxInc, maxDec);
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maximumLength(n, arr) << endl;
    return 0;
}+