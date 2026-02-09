

#include <iostream>
#include <sstream>   // include this for stringstream
using namespace std;

int main() {
    string s = "I am learning C++";
    stringstream ss(s);  // put the string into stringstream
    string word;

    while (ss >> word) {   // this extracts one word at a time (like cin >> word)
        cout << word << endl;
    }

    return 0;
}

// converts string into number

#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string s = "123";
    stringstream ss(s);   // create stringstream object with string s

    int num;
    ss >> num;            // extract integer from stringstream

    cout << "String: " << s << endl;
    cout << "Integer: " << num << endl;
    return 0;
}
