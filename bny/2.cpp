#include <bits/stdc++.h>
using namespace std;



long long convertStringToNumber(string s){
    long long num = 0;

    for(char c : s){
        num = num * 10 + (c - '0');
    }
    return num;
}

string specialNumbers(string input1){
    long long n = convertStringToNumber(input1);
    unordered_set<long long> s;

    for(long long c = 2; c * c <= n; c++){
        long long val = c * c;
        while(val <= n){
            s.insert(val);
            if(val > n / c) break;
            val *= c;
        }
    }

    long long result = n - s.size();
    return to_string(result);
}









main()
{
    string input1;

    cin >> input1;

    cout << specialNumbers(input1);

    return 0;
}