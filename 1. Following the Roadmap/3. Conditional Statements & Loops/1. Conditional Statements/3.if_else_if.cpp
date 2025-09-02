#include <iostream>
using namespace std;
int main() {
    int temp;
    cout << "Enter temperature: ";
    cin >> temp;
    if (temp > 40) {
        cout << "Very Hot!" << endl;
    } else if (temp > 30) {
        cout << "Hot" << endl;
    } else if (temp > 20) {
        cout << "Normal" << endl;
    } else if (temp > 10) {
        cout << "Cold" << endl;
    } else {
        cout << "Very Cold!" << endl;
    }
    return 0;
}
