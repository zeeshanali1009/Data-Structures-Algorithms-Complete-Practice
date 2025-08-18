#include <iostream>
using namespace std;

class Car {
    string model;
    int year;
public:
    // Non-parameterized constructor
    Car() {
        model = "Unknown";
        year = 0;
    }
    void display() {
        cout << "Model: " << model << ", Year: " << year << endl;
    }
};
int main() {
    Car c1;  // Calls default constructor
    c1.display();  // Output: Model: Unknown, Year: 0
}
