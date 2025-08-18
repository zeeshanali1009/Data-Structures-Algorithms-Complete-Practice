// Multiple constructors in the same class with different sets of parameters.
// It allows object creation in different ways, depending on available data.
#include <iostream>
using namespace std;
class Student {
public:
    string name;
    int age;
    // Default constructor
    Student() {
        name = "Unknown";
        age = 0;
    }
    // Parameterized constructor
    Student(string n, int a) {
        name = n;
        age = a;
    }
    // Copy constructor
    Student(const Student &s) {
        name = s.name;
        age = s.age;
    }
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s1;
    Student s2("Ali", 20);
    Student s3 = s2;
    s1.display();
    s2.display();
    s3.display();

    return 0;
}
