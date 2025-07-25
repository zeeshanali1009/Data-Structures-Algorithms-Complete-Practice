#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1; // Not found
}

int main() {
    int arr[] = {4, 8, 2, 10, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int index = linearSearch(arr, size, target);
    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not found." << endl;

    return 0;
}
