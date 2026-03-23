// 1594. Maximum Non Negative Product in a Matrix
// Difficulty: Medium
// https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
// Runtime: 0 ms (beats —)
// Memory: 14.1 MB (beats —)
// Submitted: 2026-03-23

class Solution {
public:
    const int MOD = 1e9 + 7;

    int maxProductPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<long long>> maxDp(rows, vector<long long>(cols));
        vector<vector<long long>> minDp(rows, vector<long long>(cols));

        maxDp[0][0] = minDp[0][0] = grid[0][0];

        for (int i = 1; i < rows; i++) {
            long long value = maxDp[i - 1][0] * grid[i][0];
            maxDp[i][0] = value;
            minDp[i][0] = value;
        }

        for (int j = 1; j < cols; j++) {
            long long value = maxDp[0][j - 1] * grid[0][j];
            maxDp[0][j] = value;
            minDp[0][j] = value;
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                long long current = grid[i][j];

                long long topMin = minDp[i - 1][j] * current;
                long long topMax = maxDp[i - 1][j] * current;
                long long leftMin = minDp[i][j - 1] * current;
                long long leftMax = maxDp[i][j - 1] * current;

                minDp[i][j] = min({topMin, topMax, leftMin, leftMax});
                maxDp[i][j] = max({topMin, topMax, leftMin, leftMax});
            }
        }

        long long result = maxDp[rows - 1][cols - 1];

        if (result < 0)
            return -1;
        return result % MOD;
    }
};
