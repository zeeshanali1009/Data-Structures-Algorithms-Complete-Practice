// Virtual Function is a member function  that you expect to be redefined in derived class.
#include <iostream>
using namespace std;
class Animal {
public:
    virtual void sound() {  // virtual function
        cout << "Animal makes sound" << endl;
    }
};
class Dog : public Animal {
public:
    void sound() override {  // overriding
        cout << "Dog barks" << endl;
    }
};
class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};
int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();
    a1->sound();  // Output: Dog barks
    a2->sound();  // Output: Cat meows
    delete a1;
    delete a2;
    return 0;
}
