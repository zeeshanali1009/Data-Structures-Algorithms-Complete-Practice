#include <iostream>
using namespace std;
int main() {
    int age = 20;
    bool hasID = true;
    // AND operator: both must be true
    cout << "Eligible (age > 18 && hasID): " << (age > 18 && hasID) << endl;
    // OR operator: at least one condition must be true
    cout << "Eligible (age > 18 || hasID): " << (age > 18 || hasID) << endl;
    // NOT operator: reverses the result
    cout << "Not Eligible (!hasID): " << (!hasID) << endl;
    return 0;
}
