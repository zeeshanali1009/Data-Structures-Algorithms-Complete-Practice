#include <iostream>
using namespace std;

void mergeInPlace(int arr1[], int m, int arr2[], int n) {
    int i = m - 1;        // last element in arr1's valid part
    int j = n - 1;        // last element in arr2
    int k = m + n - 1;    // last position in arr1

    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j])
            arr1[k--] = arr1[i--];
        else
            arr1[k--] = arr2[j--];
    }

    while (j >= 0)
        arr1[k--] = arr2[j--];
}

int main() {
    int arr1[10] = {1, 3, 5, 0, 0, 0};  // space for 3 more elements
    int arr2[] = {2, 4, 6};
    int m = 3, n = 3;

    mergeInPlace(arr1, m, arr2, n);

    cout << "In-place Merged Array: ";
    for (int i = 0; i < m + n; ++i)
        cout << arr1[i] << " ";

    return 0;
}
