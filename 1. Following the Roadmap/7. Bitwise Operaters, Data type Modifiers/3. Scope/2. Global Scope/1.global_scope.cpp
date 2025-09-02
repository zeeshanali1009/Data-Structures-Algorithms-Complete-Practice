#include <iostream>
using namespace std;

// Global variable (accessible everywhere in this file)
int globalVar = 100;

void showGlobal() {
    cout << "Inside showGlobal(): globalVar = " << globalVar << endl;
}

int main() {
    cout << "Inside main(): globalVar = " << globalVar << endl;

    // Modifying global variable
    globalVar = 200;

    cout << "Inside main() after modifying: globalVar = " << globalVar << endl;

    showGlobal(); // This will access the modified globalVar

    return 0;
}
