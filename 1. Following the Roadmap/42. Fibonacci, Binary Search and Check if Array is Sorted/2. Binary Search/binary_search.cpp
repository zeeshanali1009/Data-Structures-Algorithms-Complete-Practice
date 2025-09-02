#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)  // Base case: not found
        return -1;
    
    int mid = low + (high - low) / 2; // To avoid overflow

    if (arr[mid] == key)       // Found key
        return mid;
    else if (key < arr[mid])   // Search left half
        return binarySearch(arr, low, mid - 1, key);
    else                       // Search right half
        return binarySearch(arr, mid + 1, high, key);
}

int main() {
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}
