#include <iostream>
#include <algorithm>  // for sort
using namespace std;

void sortColors(int arr[], int n) {
    sort(arr, arr + n);
}

int main() {
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortColors(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}
