#include <iostream>
using namespace std;
class Demo {
public:
    Demo() {
        cout << "Constructor called\n";
    }
    ~Demo() {
        cout << "Destructor called\n";
    }
};
int main() {
    Demo d1;  // Constructor is called
    // Destructor will be called automatically here when d1 goes out of scope
    return 0;
}
