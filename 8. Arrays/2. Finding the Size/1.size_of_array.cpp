#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]); // Total bytes / bytes of 1 element
    cout << "Size of array = " << size << endl;
    return 0;
}
