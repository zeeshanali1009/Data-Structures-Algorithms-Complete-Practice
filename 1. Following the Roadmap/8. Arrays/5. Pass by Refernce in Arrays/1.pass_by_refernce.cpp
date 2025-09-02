#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int nums[] = {3, 6, 9};
    int size = sizeof(nums) / sizeof(nums[0]);
    printArray(nums, size); // Passed by reference automatically
    return 0;
}
