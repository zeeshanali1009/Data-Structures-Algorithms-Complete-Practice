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

    // Shallow copy constructor (default behavior)
    Student(const Student &obj) {
        name = obj.name;
        cgpaptr = obj.cgpaptr;  // copying pointer only (shallow copy)
    }

    ~Student() {
        delete cgpaptr;  // Both objects will try to delete same memory — unsafe!
    }

    void getinfo() {
        cout << "Name: " << name << ", CGPA: " << *cgpaptr << endl;
    }
};

int main() {
    Student s1("Ali", 8.5);
    Student s2 = s1;  // Shallow copy

    s2.name = "Ahmed";
    *s2.cgpaptr = 9.2;  // Changes cgpa for both s2 and s1!

    cout << "S1 info: ";
    s1.getinfo();  // CGPA will show 9.2 because memory is shared

    cout << "S2 info: ";
    s2.getinfo();

    return 0;
}
