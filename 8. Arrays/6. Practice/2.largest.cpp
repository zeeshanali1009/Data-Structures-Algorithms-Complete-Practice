#include <iostream>
using namespace std;

int main() {
    int arr[] = {22, 5, 17, 9, 31};
    int size = sizeof(arr) / sizeof(arr[0]);
    int largest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest)
            largest = arr[i];
    }
    cout << "Largest: " << largest << endl;
    return 0;
}
