#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
int count = 0;
    bool canweplaced(vector<vector<char>>& grid, int row, int col) {
    int n = grid.size();

    // check same column (only rows above)
    for (int i = 0; i < row; i++) {
        if (grid[i][col] == 'q') return false;
    }

    // directions for diagonals: upper-left and upper-right
    vector<vector<int>> dir = {{-1, -1}, {-1, 1}};

    for (auto &d : dir) {
        int r = row + d[0];
        int c = col + d[1];

        while (r >= 0 && c >= 0 && c < n) {
            if (grid[r][c] == 'q') return false;
            r += d[0];
            c += d[1];
        }
    }

    return true;
}

    int soln(vector<vector<char>>& grid, int i, int j, int n) {

        if (n == i) {
            count = count + 1;
            return count ;
        }
        for (int j = 0; j < n; j++) {
            if (canweplaced(grid, i, j)) {
                grid[i][j] = 'q';
                soln(grid, i + 1, 0, n);
                grid[i][j] = 'a';
            }
        }
        return count;
    }
    int totalNQueens(int n) {
        vector<vector<char>> grid(n, vector<char>(n, 'a'));
         return soln(grid, 0, 0, n);
    }
};
int main(){
    return 0;
}