/*Given integers M, N and K, the task is to place K knights on an M*N chessboard 
such that they don't attack each other. The knights are expected to be placed on 
different squares on the board. A knight can move two squares vertically and one square horizontally
 or two squares horizontally and one square vertically. 
 The knights attack each other if one of them can reach the other in single move.
  There are multiple ways of placing K knights on an M*N board or sometimes, no way of placing them. 
  We are expected to list out all the possible solutions
*/
#include <bits/stdc++.h>
using namespace std;

// knight attack directions (upper side only)
vector<vector<int>> dir = {
    {-2, -1}, {-2, 1},
    {-1, -2}, {-1, 2}
};

bool canweplaced(vector<vector<char>>& grid, int row, int col, int m, int n) {
    for (auto &d : dir) {
        int nr = row + d[0];
        int nc = col + d[1];

        if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
            if (grid[nr][nc] == 'k') {
                return false;
            }
        }
    }
    return true;
}

int totalWays = 0;
/*
he ONE concept you must lock in: Backtracking erases

In backtracking:

The grid is temporary

After the recursive call returns, we undo the placement

This line:

grid[row][col] = ' ';


will destroy the solution immediately after returning.

So unless you capture it at k == 0, it’s gone forever.
*/
void placedknights(vector<vector<char>>& grid,
                   int m, int n,
                   int row, int col,
                   int k) {

    // ✅ BASE CASE: all knights placed
    if (k == 0) {
        totalWays++;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-----\n";
        return;
    }

    // ❌ board finished
    if (row == m) return;

    // move to next row
    if (col == n) {
        placedknights(grid, m, n, row + 1, 0, k);
        return;
    }

    // ✅ choice 1: place knight
    if (canweplaced(grid, row, col, m, n)) {
        grid[row][col] = 'k';
        placedknights(grid, m, n, row, col + 1, k - 1);
        grid[row][col] = ' ';   // backtrack
    }

    // ✅ choice 2: skip this cell
    placedknights(grid, m, n, row, col + 1, k);
}

vector<vector<char>> knightplace(int m, int n, int k) {
    vector<vector<char>> grid(m, vector<char>(n, ' '));
    placedknights(grid, m, n, 0, 0, k);
    return grid;
}

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    knightplace(m, n, k);

    cout << "all possible ways to place knight is " << totalWays << endl;
    return 0;
}
