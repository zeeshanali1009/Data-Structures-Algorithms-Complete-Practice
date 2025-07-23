#include <iostream>
#include <string>  // Required for string
using namespace std;
int main() {
    // Declaration and Initialization of Different Data Types
    int age = 20;                      // Integer
    float height = 5.9f;              // Float (note the 'f' suffix)
    double pi = 3.1415926535;         // Double
    char grade = 'A';                 // Character
    bool isStudent = true;            // Boolean
    string name = "Zeeshan";          // String
    // Output all variables
    cout << "Name: " << name << endl;
    cout << "Age: " << age << " years" << endl;
    cout << "Height: " << height << " feet" << endl;
    cout << "Grade: " << grade << endl;
    cout << "Is Student? " << isStudent << endl; // Will print 1 (true)
    cout << "Value of Pi: " << pi << endl;
    return 0;
}
