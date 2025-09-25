/*
You have been given an integer N as input . your task is to write a 
program to print N rows of Floyad’s Triangle. Floyd's pattern is a right- 
angled triangular array of natural numbers , used for the numbering of 
lines In a printout 
. 
For N=4, 
1 
23 
456 
78910 

*/


#include <iostream>
using namespace std;

void Floyd(int n) {
    int k = 0; // Counter for numbers
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            k++;
            cout << k << " ";
        }
        cout << endl; // Newline after each row
    }
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    Floyd(n);

    return 0;
}
