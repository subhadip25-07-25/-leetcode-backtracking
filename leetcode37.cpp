#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canweplaced(int row, int col, vector<vector<char>>& board, char num) {
        // check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == num) return false;
        }

        // check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) return false;
        }

        // check 3x3 sub-box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num) return false;
            }
        }

        return true;
    }

    bool solver(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {

                    for (char num = '1'; num <= '9'; num++) {
                        if (canweplaced(i, j, board, num)) {
                            board[i][j] = num;

                            // go to next empty cell
                            if (solver(board)) return true;

                            // backtrack
                            board[i][j] = '.';
                        }
                    }
                    return false; // no number fits here
                }
            }
        }
        return true; // board completely filled
    }

    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};
