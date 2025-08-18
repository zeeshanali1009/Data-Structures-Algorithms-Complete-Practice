#include <iostream>
using namespace std;
class A{
    public:
    int x;

    void IncX(){
        x = x+1;
    }
};

int main(){
    A obj1;
    obj1.x = 10;
    cout << obj1.x << endl;
    A obj2;
    obj2.x = 100;
    cout << obj2.x << endl;
    obj1.IncX();
    cout << obj1.x << endl;

    return 0;
}