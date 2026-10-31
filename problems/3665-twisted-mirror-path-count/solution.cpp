// 3665. Twisted Mirror Path Count
// Difficulty: Medium
// https://leetcode.com/problems/twisted-mirror-path-count/
// Runtime: 53 ms (beats 90.0%)
// Memory: 223.7 MB (beats 68.3%)
// Submitted: 2026-10-31

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        vector<int> dp(grid[0].size(), 0);
        dp[0] = 1;

        for (auto row : grid) {
            int r = 0;

            for (int i = 0; i < row.size(); i++) {
                if (row[i]) swap(r, dp[i]);
                else r = dp[i] = (r + dp[i]) % MOD;
            }
        }

        return dp.back();
    }
};
