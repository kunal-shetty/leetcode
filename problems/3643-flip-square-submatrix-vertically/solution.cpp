// 3643. Flip Square Submatrix Vertically
// Difficulty: Easy
// https://leetcode.com/problems/flip-square-submatrix-vertically/
// Runtime: 0 ms (beats —)
// Memory: 33.9 MB (beats —)
// Submitted: 2026-03-21

class Solution {
public:
    vector<vector<int>>& reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k >> 1; j++)
                swap(grid[x + j][y + i], grid[x + k - j - 1][y + i]);

        return grid;
    }
};
