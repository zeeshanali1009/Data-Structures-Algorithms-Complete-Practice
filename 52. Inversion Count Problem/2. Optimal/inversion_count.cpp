#include <iostream>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;     // Starting index for left subarray
    int j = mid + 1;  // Starting index for right subarray
    int k = left;     // Starting index to be sorted
    int invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);  // All remaining elements in left are > arr[j]
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int i = left; i <= right; i++)
        arr[i] = temp[i];

    return invCount;
}

int mergeSort(int arr[], int temp[], int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        invCount += mergeSort(arr, temp, left, mid);       // Left part
        invCount += mergeSort(arr, temp, mid + 1, right);  // Right part
        invCount += merge(arr, temp, left, mid, right);    // Merge step
    }
    return invCount;
}

int countInversions(int arr[], int n) {
    int* temp = new int[n];
    int result = mergeSort(arr, temp, 0, n - 1);
    delete[] temp;
    return result;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countInversions(arr, n);
    cout << "Inversion Count (Merge Sort): " << result << endl;

    return 0;
}
