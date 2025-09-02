#include <iostream>
#include <vector>
using namespace std;

bool binarySearch2D(vector<vector<int>>& mat, int target) {
    int rows = mat.size();
    int cols = mat[0].size();

    // Step 1: Binary search on rows to find correct row
    int startRow = 0, endRow = rows - 1;
    while (startRow <= endRow) {
        int midRow = startRow + (endRow - startRow) / 2;

        // Check if target lies in this row
        if (target >= mat[midRow][0] && target <= mat[midRow][cols - 1]) {
            // Step 2: Binary search within the row
            int left = 0, right = cols - 1;
            while (left <= right) {
                int midCol = left + (right - left) / 2;
                if (mat[midRow][midCol] == target) return true;
                else if (mat[midRow][midCol] < target) left = midCol + 1;
                else right = midCol - 1;
            }
            return false; // Target not found in the row
        }
        else if (target < mat[midRow][0]) {
            endRow = midRow - 1;
        }
        else {
            startRow = midRow + 1;
        }
    }
    return false; // Target not found
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    int target = 3;

    if (binarySearch2D(matrix, target))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
