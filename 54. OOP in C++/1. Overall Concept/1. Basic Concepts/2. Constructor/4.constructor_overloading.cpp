#include <iostream>
using namespace std;
class Car {
    string model;
    int year;
public:
    // 1. Default constructor (no parameters)
    Car() {
        model = "Unknown";
        year = 0;
    }
    // 2. Parameterized constructor (two parameters)
    Car(string m, int y) {
        model = m;
        year = y;
    }
    // 3. Parameterized constructor (one parameter)
    Car(string m) {
        model = m;
        year = 2023;  // default year if only model is given
    }
    void display() {
        cout << "Model: " << model << ", Year: " << year << endl;
    }
};
int main() {
    Car c1;               // Calls default constructor
    Car c2("Toyota");     // Calls constructor with 1 string parameter
    Car c3("Honda", 2018); // Calls constructor with string and int
    c1.display();  // Output: Model: Unknown, Year: 0
    c2.display();  // Output: Model: Toyota, Year: 2023
    c3.display();  // Output: Model: Honda, Year: 2018
    return 0;
}
