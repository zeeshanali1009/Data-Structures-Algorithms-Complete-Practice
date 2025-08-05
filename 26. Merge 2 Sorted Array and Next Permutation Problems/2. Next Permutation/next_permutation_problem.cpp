#include <iostream>
#include <algorithm>
using namespace std;

void nextPermutation(int arr[], int n) {
    int index = -1;

    // Step 1: Find the pivot
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            index = i;
            break;
        }
    }

    // Step 2: If no pivot, reverse whole array (last permutation case)
    if (index == -1) {
        reverse(arr, arr + n);
        return;
    }

    // Step 3: Find next greater element from the end and swap with pivot
    for (int i = n - 1; i > index; i--) {
        if (arr[i] > arr[index]) {
            swap(arr[i], arr[index]);
            break;
        }
    }

    // Step 4: Reverse the suffix (after pivot)
    reverse(arr + index + 1, arr + n);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextPermutation(arr, n);

    cout << "Next permutation: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
