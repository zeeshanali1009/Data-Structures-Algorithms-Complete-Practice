#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    if (n == 0 || n == 1)  // Base case
        return true;
    
    if (arr[0] > arr[1])   // Current pair not sorted
        return false;
    
    return isSorted(arr + 1, n - 1); // Check rest of the array
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (isSorted(arr, n))
        cout << "Array is sorted";
    else
        cout << "Array is not sorted";

    return 0;
}
