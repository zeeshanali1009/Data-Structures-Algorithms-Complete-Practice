#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 10, 15, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        cout << "Element at index " << i << " = " << arr[i] << endl;
    }

    return 0;
}
