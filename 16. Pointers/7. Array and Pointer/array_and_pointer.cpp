#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30};
    int* p = arr;

    cout << "arr[0]: " << *p << endl;
    cout << "arr[1]: " << *(p + 1) << endl;
    return 0;
}
