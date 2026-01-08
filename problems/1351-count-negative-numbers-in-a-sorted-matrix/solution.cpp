// 1351. Count Negative Numbers in a Sorted Matrix
// Difficulty: Easy
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Runtime: 0 ms (beats —)
// Memory: 14.1 MB (beats —)
// Submitted: 2026-01-08

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i < rows; i++) {        // row
            for (int j = 0; j < cols; j++) {    // column
                if (grid[i][j] < 0)
                    count++;
            }
        }
        return count;
    }
};
