#include <iostream>
using namespace std;

#define N 9

// Function to check if placing 'dig' at board[row][col] is safe
bool isSafe(int board[N][N], int row, int col, int dig) {
    // 1. Horizontal check (row)
    for (int j = 0; j < N; j++) {
        if (board[row][j] == dig)
            return false;
    }

    // 2. Vertical check (column)
    for (int i = 0; i < N; i++) {
        if (board[i][col] == dig)
            return false;
    }

    // 3. 3x3 grid check
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == dig)
                return false;
        }
    }

    return true;
}

// Recursive function to solve sudoku
bool solveSudoku(int board[N][N], int row, int col) {
    // Base case: if we reach past last row, sudoku solved
    if (row == N) return true;

    // Next cell
    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol == N) {
        nextRow++;
        nextCol = 0;
    }

    // If cell already filled, move to next
    if (board[row][col] != 0) {
        return solveSudoku(board, nextRow, nextCol);
    }

    // Try digits 1-9
    for (int dig = 1; dig <= 9; dig++) {
        if (isSafe(board, row, col, dig)) {
            board[row][col] = dig; // Place digit
            if (solveSudoku(board, nextRow, nextCol))
                return true;
            board[row][col] = 0; // Backtrack
        }
    }

    return false; // No valid digit found
}

// Print sudoku board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int board[N][N] = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    if (solveSudoku(board, 0, 0)) {
        cout << "Solved Sudoku:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}
