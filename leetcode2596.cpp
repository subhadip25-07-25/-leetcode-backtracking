#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = { {-2, 1}, {-2, -1}, { 2, 1}, { 2, -1}, {-1, 2}, { 1, 2}, {-1,-2}, { 1,-2} };
bool isvalid(vector<vector<int>>& grid, int i, int j) {
    int n = grid.size();

    // ✅ base case: reached last number
    if (grid[i][j] == n*n - 1)
        return true;

    int nextVal = grid[i][j] + 1;

    for (auto &ele : dir) {
        int nr = i + ele[0];
        int nc = j + ele[1];

        if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
            grid[nr][nc] == nextVal) {

            // ✅ propagate result
            if (isvalid(grid, nr, nc))
                return true;
        }
    }

    // ❌ no valid next move found
    return false;
}
bool is_valid(vector<vector<int>>&grid,int i , int j , int val){
     int n = grid.size();
    if(val==n*n-1){
        return true;
    }
    for (auto &ele : dir) {
        int nr = i + ele[0];
        int nc = j + ele[1];
         if (nr >= 0 && nc >= 0 && nr < n && nc < n &&grid[nr][nc] == val+1) {
            if(is_valid(grid, nr,nc, val+1)){
                return true;
            }
         }
    }
    
    return false;
}
 bool isvalid_optimal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> pos(n * n);
        // store the pos
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < n * n - 1; i++) {
            int r1 = pos[i].first;
            int c1 = pos[i].second;
            int r2 = pos[i + 1].first;
            int c2 = pos[i + 1].second;
            int dx = abs(r1 - r2);
            int dy = abs(c1 - c2);
            if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2))) {
                return false;
            }
        }
        return true;
    }
bool checkValidGrid(vector<vector<int>>& grid) {
        // must start from 0 at (0,0)
        if (grid[0][0] != 0)
            return false;

        return is_valid(grid, 0, 0, 0);
    }
