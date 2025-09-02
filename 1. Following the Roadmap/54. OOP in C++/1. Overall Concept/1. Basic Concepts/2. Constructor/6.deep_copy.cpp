#include <iostream>
using namespace std;

class Student {
public:
    double *cgpaptr;
    string name;

    // Constructor
    Student(string n, double cgpa) {
        name = n;
        cgpaptr = new double(cgpa);
    }

    // Deep copy constructor
    Student(const Student &obj) {
        name = obj.name;
        cgpaptr = new double(*obj.cgpaptr);  // allocate new memory and copy value
    }

    ~Student() {
        delete cgpaptr;  // safely free memory
    }

    void getinfo() {
        cout << "Name: " << name << ", CGPA: " << *cgpaptr << endl;
    }
};

int main() {
    Student s1("Ali", 8.5);
    Student s2 = s1;  // Deep copy

    s2.name = "Ahmed";
    *s2.cgpaptr = 9.2;  // Only s2's CGPA changes

    cout << "S1 info: ";
    s1.getinfo();  // CGPA remains 8.5

    cout << "S2 info: ";
    s2.getinfo();  // CGPA is 9.2

    return 0;
}
