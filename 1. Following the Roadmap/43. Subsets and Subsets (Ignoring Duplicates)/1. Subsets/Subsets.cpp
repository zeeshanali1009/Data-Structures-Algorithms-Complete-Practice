#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int> &arr, vector<int> &subset, int index) {
    if (index == arr.size()) {  // Base case: all elements considered
        cout << "{ ";
        for (int x : subset)
            cout << x << " ";
        cout << "}" << endl;
        return;
    }

    // Include current element
    subset.push_back(arr[index]);
    printSubsets(arr, subset, index + 1);

    // Exclude current element (backtrack)
    subset.pop_back();
    printSubsets(arr, subset, index + 1);
}

int main() {
    vector<int> arr = {1, 2, 3};  // Example array
    vector<int> subset;

    cout << "All subsets of the array are:\n";
    printSubsets(arr, subset, 0);

    return 0;
}
