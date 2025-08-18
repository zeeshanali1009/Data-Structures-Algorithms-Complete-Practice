#include <iostream>
using namespace std;
class Car {
    string model;
    int year;
public:
    // Parameterized constructor
    Car(string m, int y) {
        model = m;
        year = y;
    }
    void display() {
        cout << "Model: " << model << ", Year: " << year << endl;
    }
};
int main() {
    Car c1("Toyota", 2020);  // Calls parameterized constructor
    c1.display();  // Output: Model: Toyota, Year: 2020
}
