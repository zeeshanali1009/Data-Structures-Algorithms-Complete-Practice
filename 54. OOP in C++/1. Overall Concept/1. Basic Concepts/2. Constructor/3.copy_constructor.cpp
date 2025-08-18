#include <iostream>
using namespace std;
class Car {
    string model;
    int year;
public:
    Car(string m, int y) {
        model = m;
        year = y;
    }
    void display() {
        cout << "Model: " << model << ", Year: " << year << endl;
    }
};
int main() {
    Car c1("Honda", 2019);
    Car c2 = c1;  // Calls copy constructor
    c2.display();  // Output: Model: Honda, Year: 2019
}
