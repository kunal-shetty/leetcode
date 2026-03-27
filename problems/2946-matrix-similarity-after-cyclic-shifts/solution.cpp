// 2946. Matrix Similarity After Cyclic Shifts
// Difficulty: Easy
// https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/
// Runtime: 0 ms (beats —)
// Memory: 31.3 MB (beats —)
// Submitted: 2026-03-27

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k %= n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    if (mat[i][j] != mat[i][(j + k) % n])
                        return false;
                } else {
                    if (mat[i][j] != mat[i][(j - k + n) % n])
                        return false;
                }
            }
        }

        return true;
    }
};
