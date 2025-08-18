#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &matrix, int r, int c, string path, vector<string> &ans) {
    int n = matrix.size();

    // Out of bounds or blocked
    if (r < 0 || c < 0 || r >= n || c >= n || matrix[r][c] == 0 || matrix[r][c] == -1)
        return;

    // Destination reached
    if (r == n - 1 && c == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark visited
    matrix[r][c] = -1;

    // Explore all 4 directions
    helper(matrix, r + 1, c, path + 'D', ans); // Down
    helper(matrix, r - 1, c, path + 'U', ans); // Up
    helper(matrix, r, c + 1, path + 'R', ans); // Right
    helper(matrix, r, c - 1, path + 'L', ans); // Left

    // Backtrack
    matrix[r][c] = 1;
}

vector<string> findPath(vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<string> ans;

    if (matrix[0][0] == 0 || matrix[n-1][n-1] == 0) 
        return ans; // No path if start or end blocked

    helper(matrix, 0, 0, "", ans);

    return ans;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    vector<string> paths = findPath(maze);

    if (paths.empty()) {
        cout << "No path found\n";
    } else {
        cout << "Possible paths:\n";
        for (auto &p : paths) {
            cout << p << "\n";
        }
    }

    return 0;
}
