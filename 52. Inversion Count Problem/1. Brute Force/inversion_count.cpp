#include <iostream>
using namespace std;

int countInversionsBruteForce(int arr[], int n) {
    int invCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                invCount++;
        }
    }
    return invCount;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countInversionsBruteForce(arr, n);
    cout << "Inversion Count (Brute Force): " << result << endl;

    return 0;
}
