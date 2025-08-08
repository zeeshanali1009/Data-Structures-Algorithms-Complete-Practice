// 1._Spiral_Matrix.cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows = 4, cols = 4;
    vector<vector<int>> matrix = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    int srow = 0, scol = 0;
    int erow = rows - 1, ecol = cols - 1;

    while (srow <= erow && scol <= ecol) {
        // Top row
        for (int j = scol; j <= ecol; j++) {
            cout << matrix[srow][j] << " ";
        }

        // Right column
        for (int i = srow + 1; i <= erow; i++) {
            cout << matrix[i][ecol] << " ";
        }

        // Bottom row (check if srow != erow to avoid duplicate printing)
        if (srow != erow) {
            for (int j = ecol - 1; j >= scol; j--) {
                cout << matrix[erow][j] << " ";
            }
        }

        // Left column (check if scol != ecol to avoid duplicate printing)
        if (scol != ecol) {
            for (int i = erow - 1; i > srow; i--) {
                cout << matrix[i][scol] << " ";
            }
        }

        srow++;
        scol++;
        erow--;
        ecol--;
    }

    return 0;
}
