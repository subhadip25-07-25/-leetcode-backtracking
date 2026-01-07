// n queeesns problem 
/*
/*he n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool queenplaceable(int currow, int col, vector<string> &grid, int n) {
        // Check column
        for (int i = currow - 1; i >= 0; i--) {
            if (grid[i][col] == 'Q') return false;
        }
        // Check upper-left diagonal
        for (int i = currow - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j] == 'Q') return false;
        }
        // Check upper-right diagonal
        for (int i = currow - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (grid[i][j] == 'Q') return false;
        }
        return true;
    }

    void nqueen(int currrow, int n, vector<string> &grid, vector<vector<string>> &result) {
        if (currrow == n) {  // Base case: all queens are placed
            result.push_back(grid);  // Add current board configuration to result
            return;
        }
        for (int col = 0; col < n; col++) {
            if (queenplaceable(currrow, col, grid, n)) {
                grid[currrow][col] = 'Q';  // Place queen
                nqueen(currrow + 1, n, grid, result);  // Recursively place next queen
                grid[currrow][col] = '.';  // Backtrack and remove queen
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;  // To store all distinct solutions
        vector<string> grid(n, string(n, '.'));  // Initialize empty chessboard
        nqueen(0, n, grid, result);  // Start solving N-Queens
        return result;
    }
};
int main(){
    return 0 ;

}