#include <iostream>
using namespace std;
class A {
private:
    int data = 99;

    // Giving B full access
    friend class B;
};
class B {
public:
    void showData(A obj) {
        cout << "Accessed private data of A: " << obj.data << endl;
    }
};
int main() {
    A objA;
    B objB;
    objB.showData(objA);  // Can access A’s private member
    return 0;
}
