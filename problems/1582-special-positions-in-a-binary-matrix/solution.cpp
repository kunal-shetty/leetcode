// 1582. Special Positions in a Binary Matrix
// Difficulty: Easy
// https://leetcode.com/problems/special-positions-in-a-binary-matrix/
// Runtime: 0 ms (beats —)
// Memory: 16.9 MB (beats —)
// Submitted: 2026-05-25

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int m = mat.size(), n = mat[0].size();
        vector<int> rowSum(m, 0);
        vector<int> colSum(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1)
                    count++;
            }
        }

        return count;
    }
};
