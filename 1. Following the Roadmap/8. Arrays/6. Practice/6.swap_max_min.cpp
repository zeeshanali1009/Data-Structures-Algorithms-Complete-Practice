#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 2, 9, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxIndex = 0, minIndex = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap max and min
    int temp = arr[maxIndex];
    arr[maxIndex] = arr[minIndex];
    arr[minIndex] = temp;

    cout << "Array after swapping max and min: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}
