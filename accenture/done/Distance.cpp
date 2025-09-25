// '''

// Ques: The program is supposed to calculate the sum of  distance between three points from each other.

// For
// x1 = 1 y1 = 1
// x2 = 2 y2 = 4
// x3 = 3 y3 = 6

// Distance is calculated as : sqrt(x2-x1)2 + (y2-y1)2

// '''

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function to calculate distance between two points
double calculate_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    double x1, y1, x2, y2, x3, y3;

    cout << "Enter coordinates for point 1 (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates for point 2 (x2 y2): ";
    cin >> x2 >> y2;
    cout << "Enter coordinates for point 3 (x3 y3): ";
    cin >> x3 >> y3;

    double first_diff = calculate_distance(x1, y1, x2, y2);   // AB
    double second_diff = calculate_distance(x2, y2, x3, y3);  // BC
    double third_diff = calculate_distance(x1, y1, x3, y3);   // AC

    double total = first_diff + second_diff + third_diff;

    cout << fixed << setprecision(2);
    cout << "Distances:\n";
    cout << "Between point 1 and point 2: " << first_diff << endl;
    cout << "Between point 2 and point 3: " << second_diff << endl;
    cout << "Between point 1 and point 3: " << third_diff << endl;
    cout << "Total sum of distances: " << total << endl;

    return 0;
}
