/*
Problem Statement 

Alice has a collection of songs represented as a string S where each character reperesents a song. Aplaylisy is the substring of the given string with exactly K number of songs. She wants to create a playlist that contains maximum number of her favourite song which is 'a'. Your task is to find and return an integer value representing the maximum number of favourite songs that she can get in a single playlist.

Input: S = "acdbaaca"
       K = 3

Output: 2

Explanation: Substring of S of size 3: {"acd", "cdb", "dba", "baa", "aac", "aca"} 

So "a" is coming max 2 times in substring

*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int MaxSong(string s, int k) {
    int n = s.length();
    if (k > n) return 0; // invalid case

    int count = 0, maxCount = 0;

    // count 'a' in the first window
    for (int j = 0; j < k; j++) {
        if (s[j] == 'a') count++;
    }
    maxCount = count;

    int start = 0;      // left index of window
    int end = k;        // right index (next char to include)

    // sliding with while loop
    while (end < n) {
        if (s[start] == 'a') count--; // remove left char
        if (s[end] == 'a') count++;   // add right char

        maxCount = max(maxCount, count);

        start++;
        end++;
    }

    return maxCount;
}

int main() {
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter K: ";
    cin >> k;

    cout << "Output: " << MaxSong(s, k) << endl;

    return 0;
}
