#include <iostream>
using namespace std;

const int N = 5;  // Use small N for faster results
int board[N][N];

// Function to print the board
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << "\t";
        cout << endl;
    }
}

// Check if the current move is valid
bool isValid(int r, int c) {
    return (r >= 0 && c >= 0 && r < N && c < N && board[r][c] == -1);
}

// Recursive knight tour function
bool knightTour(int r, int c, int expVal) {
    if (!isValid(r, c))
        return false;

    board[r][c] = expVal;

    if (expVal == N * N - 1)
        return true;

    // Try all 8 possible moves
    bool ans1 = knightTour(r + 2, c + 1, expVal + 1);
    bool ans2 = knightTour(r + 1, c + 2, expVal + 1);
    bool ans3 = knightTour(r - 1, c + 2, expVal + 1);
    bool ans4 = knightTour(r - 2, c + 1, expVal + 1);
    bool ans5 = knightTour(r - 2, c - 1, expVal + 1);
    bool ans6 = knightTour(r - 1, c - 2, expVal + 1);
    bool ans7 = knightTour(r + 1, c - 2, expVal + 1);
    bool ans8 = knightTour(r + 2, c - 1, expVal + 1);

    // If any move worked, return true
    if (ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8)
        return true;

    // Backtrack
    board[r][c] = -1;
    return false;
}

int main() {
    // Initialize the board
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;

    // Start the knight at position (0, 0)
    if (knightTour(0, 0, 0)) {
        cout << "Knight's Tour Found:\n";
        printBoard();
    } else {
        cout << "No Knight's Tour possible.\n";
    }

    return 0;
}
