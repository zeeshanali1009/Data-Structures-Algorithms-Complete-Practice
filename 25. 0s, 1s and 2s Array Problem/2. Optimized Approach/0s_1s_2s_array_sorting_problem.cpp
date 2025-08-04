#include <iostream>
using namespace std;

void sortColors(int arr[], int n) {
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) count0++;
        else if (arr[i] == 1) count1++;
        else count2++;
    }

    int i = 0;
    while (count0--) arr[i++] = 0;
    while (count1--) arr[i++] = 1;
    while (count2--) arr[i++] = 2;
}

int main() {
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortColors(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}
