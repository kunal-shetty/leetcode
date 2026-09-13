// 4052. Cyclically Shift Rows and Columns
// Difficulty: Easy
// https://leetcode.com/problems/cyclically-shift-rows-and-columns/
// Runtime: 7 ms (beats —)
// Memory: 73.5 MB (beats —)
// Submitted: 2026-09-13

class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> rowGrid(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                rowGrid[i][(j - rowShift[i] + n) %n] = grid[i][j];
            }
        }
        vector<vector<int>> ans(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[(i - colShift[j] + n) %n][j] = rowGrid[i][j];
            }
        }
        return ans;
    }
};
