#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 3;
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int maxSum = 0, rowIndex = -1;

    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            rowIndex = i;
        }
    }

    cout << "Max row sum: " << maxSum << " in row " << rowIndex << endl;
}
