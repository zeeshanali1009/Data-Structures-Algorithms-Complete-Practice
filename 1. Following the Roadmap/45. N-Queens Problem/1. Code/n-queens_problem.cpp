#include <iostream>
using namespace std;

#define N 4  // you can change this value

// Function to check if it's safe to place a queen
bool isSafe(char board[N][N], int row, int col) {
    // 1. Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return false;
    }

    // 2. Check row (not needed if we place row by row, but keeping as per notes)
    for (int j = 0; j < col; j++) {
        if (board[row][j] == 'Q')
            return false;
    }

    // 3. Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    // 4. Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }

    return true; // Safe to place queen
}

// Recursive function to place queens
bool nQueens(char board[N][N], int row) {
    if (row == N) { // Base case: all queens placed
        // Print solution
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    bool foundSolution = false;

    for (int j = 0; j < N; j++) {
        if (isSafe(board, row, j)) {
            board[row][j] = 'Q';             // Place queen
            foundSolution = nQueens(board, row + 1) || foundSolution;
            board[row][j] = '.';             // Backtrack
        }
    }
    return foundSolution;
}

int main() {
    char board[N][N];
    // Initialize board with '.'
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = '.';

    if (!nQueens(board, 0)) {
        cout << "No solution exists!" << endl;
    }
    return 0;
}
