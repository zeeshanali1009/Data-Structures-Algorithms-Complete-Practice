#include <iostream>
#include <vector>
using namespace std;

void printPermutations(vector<int> &arr, int index) {
    if (index == arr.size()) {   // Base case: a permutation is ready
        for (int x : arr)
            cout << x << " ";
        cout << endl;
        return;
    }

    for (int i = index; i < arr.size(); i++) {
        swap(arr[index], arr[i]);           // Swap to fix element at index
        printPermutations(arr, index + 1);  // Recurse for next index
        swap(arr[index], arr[i]);           // Backtrack
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    cout << "All permutations of the array are:\n";
    printPermutations(arr, 0);
    return 0;
}
