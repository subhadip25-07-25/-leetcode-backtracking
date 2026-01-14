#include <bits/stdc++.h>
using namespace std;

// 8 possible knight moves
vector<vector<int>> dir = {
    {-2, 1}, {-2, -1},
    { 2, 1}, { 2, -1},
    {-1, 2}, { 1, 2},
    {-1,-2}, { 1,-2}
};

bool canWePlace(vector<vector<int>>& grid, int n, int i, int j) {
    return (i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == -1);
}

bool knights(int n, vector<vector<int>>& grid, int i, int j, int count) {

    // base case: all cells visited
    if (count == n * n) {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                cout << setw(2) << grid[r][c] << " ";
            }
            cout << endl;
        }
        return true;
    }

    // try all 8 knight moves
    for (auto &d : dir) {
        int ni = i + d[0];
        int nj = j + d[1];

        if (canWePlace(grid, n, ni, nj)) {
            grid[ni][nj] = count;

            if (knights(n, grid, ni, nj, count + 1))
                return true;   // stop after one solution

            grid[ni][nj] = -1; // backtrack
        }
    }

    return false;
}

int main() {
    int n = 8;
    vector<vector<int>> grid(n, vector<int>(n, -1));

    // starting position
    grid[0][0] = 0;

    knights(n, grid, 0, 0, 1);

    return 0;
}
