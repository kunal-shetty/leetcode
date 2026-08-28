// 3195. Find the Minimum Area to Cover All Ones I
// Difficulty: Medium
// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
// Runtime: 277 ms (beats —)
// Memory: 133.7 MB (beats —)
// Submitted: 2026-08-28

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minRow = m, maxRow = -1;
        int minCol = n, maxCol = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};
