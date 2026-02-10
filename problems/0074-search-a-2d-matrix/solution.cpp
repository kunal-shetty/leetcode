// 74. Search a 2D Matrix
// Difficulty: Medium
// https://leetcode.com/problems/search-a-2d-matrix/
// Runtime: 0 ms (beats —)
// Memory: 13.3 MB (beats —)
// Submitted: 2026-02-10

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = -1;

        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] <= target) {
                row = i;
            } else {
                break;
            }
        }

        if (row == -1) return false;
        for (int j = 0; j < matrix[row].size(); j++) {
            if (matrix[row][j] == target)
                return true;
        }

        return false;
    }
};
