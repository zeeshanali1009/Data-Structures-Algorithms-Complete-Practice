#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printUniqueSubsets(vector<int> &arr, vector<int> &subset, int index) {
    cout << "{ ";
    for (int x : subset)
        cout << x << " ";
    cout << "}" << endl;

    for (int i = index; i < arr.size(); i++) {
        if (i > index && arr[i] == arr[i - 1])  // Skip duplicates at same level
            continue;

        subset.push_back(arr[i]);               // Include current element
        printUniqueSubsets(arr, subset, i + 1);
        subset.pop_back();                      // Backtrack
    }
}

int main() {
    vector<int> arr = {1, 2, 2};
    vector<int> subset;

    sort(arr.begin(), arr.end()); // Sort array to handle duplicates

    cout << "All unique subsets of the array are:\n";
    printUniqueSubsets(arr, subset, 0);

    return 0;
}
