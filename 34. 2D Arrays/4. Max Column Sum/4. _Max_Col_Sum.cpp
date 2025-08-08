#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 3;
    int arr[3][3] = {
        {1, 2, 3},
        {4, 15, 6},
        {7, 8, 9}
    };

    int maxSum = 0, colIndex = -1;

    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += arr[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            colIndex = j;
        }
    }

    cout << "Max column sum: " << maxSum << " in column " << colIndex << endl;
}
