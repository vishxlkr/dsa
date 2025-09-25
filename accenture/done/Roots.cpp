// # Function to find the roots of a quadratic equation ax^2 + bx + c = 0
// # Formula:   +X = (-b + underoot b2 - 4ac/2a)
// #            -X = (-b - underoot b2 - 4ac/2a)

#include <iostream>
#include <cmath>   // for sqrt function
using namespace std;

void findRoots(double a, double b, double c) {
    if (a == 0) {
        cout << "Not a quadratic equation (a cannot be 0)." << endl;
        return;
    }

    double discriminant = b * b - 4 * a * c;
    double root1, root2;

    if (discriminant > 0) {
        // Two real and distinct roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and distinct: " << root1 << " , " << root2 << endl;
    }
    else if (discriminant == 0) {
        // Two real and equal roots
        root1 = root2 = -b / (2 * a);
        cout << "Roots are real and equal: " << root1 << endl;
    }
    else {
        // Complex roots
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-discriminant) / (2 * a);
        cout << "Roots are complex: "
             << realPart << " + " << imagPart << "i , "
             << realPart << " - " << imagPart << "i" << endl;
    }
}

int main() {
    double a, b, c;
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;

    findRoots(a, b, c);

    return 0;
}
