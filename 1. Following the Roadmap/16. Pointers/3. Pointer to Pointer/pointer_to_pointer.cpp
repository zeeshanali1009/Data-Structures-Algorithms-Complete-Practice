#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* p = &a;
    int** pp = &p;

    cout << "Value of a: " << a << endl;
    cout << "Value via *p: " << *p << endl;
    cout << "Value via **pp: " << **pp << endl;
    return 0;
}
