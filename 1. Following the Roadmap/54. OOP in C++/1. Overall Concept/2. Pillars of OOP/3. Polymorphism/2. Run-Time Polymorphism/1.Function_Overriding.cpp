// A child class redefines a function from its base class. Requires a virtual keyword in base class.
// It supports dynamic behavior, especially when using base class pointers.
#include <iostream>
using namespace std;
class Animal {
public:
    virtual void speak() {
        cout << "Animal makes a sound" << endl;
    }
};
class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks" << endl;
    }
};
class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows" << endl;
    }
};
int main() {
    Animal* a;
    Dog d;
    Cat c;
    a = &d;
    a->speak(); // Outputs: Dog barks
    a = &c;
    a->speak(); // Outputs: Cat meows
    return 0;
}
