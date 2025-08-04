#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int* p = &a;

    cout << "Address stored in pointer p: " << p << endl;
    cout << "Value pointed by p: " << *p << endl;
    return 0;
}
