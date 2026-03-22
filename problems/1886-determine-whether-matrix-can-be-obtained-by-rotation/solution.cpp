// 1886. Determine Whether Matrix Can Be Obtained By Rotation
// Difficulty: Easy
// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
// Runtime: 0 ms (beats —)
// Memory: 15.2 MB (beats —)
// Submitted: 2026-03-22

class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>> matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = i + 1; j < col; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int k = 0; k < row; k++) {
            reverse(matrix[k].begin(), matrix[k].end());
        }
        return matrix;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> rotate90mat = rotate(mat);
        vector<vector<int>> rotate180mat = rotate(rotate90mat);
        vector<vector<int>> rotate270mat = rotate(rotate180mat);
        return mat == target || rotate90mat == target || rotate180mat == target || rotate270mat == target;
    }
};
