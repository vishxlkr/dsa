#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {-1,+1,-2,+2,-1,+1,-2,+2};
vector<int> dy = {+2,+2,+1,+1,-2,-2,-1,-1};

// Check if the cell (i, j) is inside the board and unvisited
bool isSafe(vector<vector<int>>& grid, int n, int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == -1;
}

// Display the board
void displayGrid(vector<vector<int>> &grid, int n) {
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "*********" << endl;
}

// Recursive backtracking function to perform Knight's Tour
void f(vector<vector<int>> &grid, int n, int i, int j, int count) {
    grid[i][j] = count;

    if (count == n * n - 1) {
        displayGrid(grid, n);
        grid[i][j] = -1; // Backtrack
        return;
    }

    for (int t = 0; t < 8; t++) {
        int ni = i + dx[t];
        int nj = j + dy[t];

        if (isSafe(grid, n, ni, nj)) {
            f(grid, n, ni, nj, count + 1);
        }
    }

    grid[i][j] = -1; // Backtrack
}

// Initializes the board and starts the tour
void knightsTour(int n, int start_i, int start_j) {
    vector<vector<int>> grid(n, vector<int>(n, -1));
    f(grid, n, start_i, start_j, 0);
}

int main() {
    int n = 5; // Use small board (e.g., 5x5) for feasible results
    knightsTour(n, 0, 0); // Start from top-left corner (0, 0)
    return 0;
}
