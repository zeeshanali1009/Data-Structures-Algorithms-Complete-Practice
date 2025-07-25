#include <iostream>
using namespace std;

int main() {
    int arr[] = {22, 5, 17, 9, 31};
    int size = sizeof(arr) / sizeof(arr[0]);
    int smallest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest)
            smallest = arr[i];
    }

    cout << "Smallest: " << smallest << endl;
    return 0;
}
