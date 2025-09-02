#include <iostream>
using namespace std;
int main() {
    int intVal = 10;
    float floatVal = 3.5;
    // int is automatically converted to float during addition
    float result = intVal + floatVal;
    cout << "Result (implicit conversion): " << result << endl;
    return 0;
}
