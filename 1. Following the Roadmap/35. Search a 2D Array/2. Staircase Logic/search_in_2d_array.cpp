#include <iostream>
#include <vector>
using namespace std;

bool staircaseSearch(vector<vector<int>>& mat, int target) {
    int rows = mat.size();
    int cols = mat[0].size();

    int r = 0, c = cols - 1; // Start from top-right corner
    while (r < rows && c >= 0) {
        if (mat[r][c] == target) return true;
        else if (target < mat[r][c]) c--; // Move left
        else r++; // Move down
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target = 5;

    if (staircaseSearch(matrix, target))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
