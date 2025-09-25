/*
Problem Statement :

N light bulbs are connected by a wire. Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb. Given an inital state of all bulbs, Find the minimum number of switches you have to press to turn on all the bulbs. You can press the same switch multiple times.

Note: 0 represents the bulb is off and 1 represents the bulb is on.

Note: A[] = [0 1 0 1]
Output: 4

Explanation:
Press switch 0: [1 0 1 0] //1
Press switch 1: [1 1 0 1] //2
Press switch 2: [1 1 1 0] //3
Press switch 3: [1 1 1 1] //4

Input: A[] = [1 0 0 0 0]
Output: 1

*/



// import java.util.*;
// public class BulbSwitch
// {
//     public static int BulbSwitch(int arr[], int n)
//     {
//         int count = 0;
//         for(int i = 0; i < n; i++){
//             if(arr[i] == 0){
//                 arr[i] = 1;
//                 for(int j = i+1; j < n; j++){
//                     if(arr[j] == 1){
//                         arr[j] = 0;
//                     }else{
//                         arr[j] = 1;
//                     }
//                 }
//                 count++;
//             }
//         }
//         return count;
//     }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);

//         int arr[] = {0,1,0,1};
//         int n = arr.length;

//         System.out.println("Minimum no of switches to press: " + BulbSwitch(arr, n));
//     }
// } 


#include <iostream>
#include <vector>
using namespace std;

int minSwitchPresses(vector<int>& bulbs) {
    int flips = 0;   // how many times we flipped so far
    int count = 0;   // number of presses

    for (int i = 0; i < bulbs.size(); i++) {
        int effectiveState = (bulbs[i] + flips) % 2; // bulb state after flips
        if (effectiveState == 0) {  // OFF
            count++;
            flips++;  // pressing this switch flips all future bulbs
        }
    }
    return count;
}

int main() {
    vector<int> A1 = {0, 1, 0, 1};
    cout << "Output: " << minSwitchPresses(A1) << endl;  // 4

    vector<int> A2 = {1, 0, 0, 0, 0};
    cout << "Output: " << minSwitchPresses(A2) << endl;  // 1

    return 0;
}
