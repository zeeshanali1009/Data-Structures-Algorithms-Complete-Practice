// A derived class inherits from more than one base class.
#include <iostream>
using namespace std;

class Father {
public:
    void traitsFromFather() {
        cout << "Strong and tall" << endl;
    }
};
class Mother {
public:
    void traitsFromMother() {
        cout << "Kind and smart" << endl;
    }
};
class Child : public Father, public Mother {
public:
    void ownTraits() {
        cout << "Child has mixed traits" << endl;
    }
};
int main() {
    Child c;
    c.traitsFromFather();
    c.traitsFromMother();
    c.ownTraits();
    return 0;
}
