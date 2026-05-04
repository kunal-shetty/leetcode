// 48. Rotate Image
// Difficulty: Medium
// https://leetcode.com/problems/rotate-image/
// Runtime: 0 ms (beats —)
// Memory: 10.2 MB (beats —)
// Submitted: 2026-05-04

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
