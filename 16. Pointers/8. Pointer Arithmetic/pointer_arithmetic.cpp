#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 10, 15};
    int* p = arr;

    cout << "Current: " << *p << endl;    // 5
    p++;
    cout << "Next: " << *p << endl;       // 10
    p--;
    cout << "Back to first: " << *p << endl; // 5
    cout << "Third: " << *(p + 2) << endl;   // 15

    return 0;
}
