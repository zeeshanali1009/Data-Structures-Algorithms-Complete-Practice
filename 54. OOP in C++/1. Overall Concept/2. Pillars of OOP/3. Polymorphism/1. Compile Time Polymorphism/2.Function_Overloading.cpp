// Same function name but with different parameters (number or type). It happens at compile time.
// Allows us to define multiple versions of a function to handle different data types or scenarios.
#include <iostream>
using namespace std;
class Print {
public:
    void show(int x) {
        cout << "Integer: " << x << endl;
    }
    void show(double x) {
        cout << "Double: " << x << endl;
    }
};
