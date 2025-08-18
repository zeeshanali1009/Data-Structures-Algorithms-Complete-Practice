// A class is derived from a class which is already derived from another class.
#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Animal makes a sound" << endl;
    }
};
class Mammal : public Animal {
public:
    void feed() {
        cout << "Mammal feeds milk" << endl;
    }
};
class Dog : public Mammal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};
int main() {
    Dog d;
    d.sound(); // from Animal
    d.feed();  // from Mammal
    d.bark();  // from Dog
    return 0;
}
