// A combination of two or more types of inheritance (for example:  combination of multiple and multilevel).
#include <iostream>
using namespace std;

class Person {
public:
    void speak() {
        cout << "Person can speak" << endl;
    }
};
class Father : virtual public Person {
public:
    void job() {
        cout << "Father is a doctor" << endl;
    }
};
class Mother : virtual public Person {
public:
    void hobby() {
        cout << "Mother loves gardening" << endl;
    }
};
class Child : public Father, public Mother {
public:
    void play() {
        cout << "Child loves to play" << endl;
    }
};
int main() {
    Child c;
    c.speak();  // from Person (avoids ambiguity via virtual inheritance)
    c.job();    // from Father
    c.hobby();  // from Mother
    c.play();   // from Child
    return 0;
}
