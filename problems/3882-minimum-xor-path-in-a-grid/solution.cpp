// 3882. Minimum XOR Path in a Grid
// Difficulty: Medium
// https://leetcode.com/problems/minimum-xor-path-in-a-grid/
// Runtime: 90 ms (beats 98.3%)
// Memory: 41.7 MB (beats 86.8%)
// Submitted: 2026-10-28

using bits = bitset<1024>;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<bits> dp(n);
        dp[0][0] = 1;

        for (auto g : grid)
            for (int j = 0; j < n; j++) {
                bits r = dp[j] | (j ? dp[j - 1] : bits());
                dp[j].reset();
                for (int x = 0; x < 1024; x++) {
                    if (r[x]) dp[j][x ^ g[j]] = 1;
                }
            }

        int res = 0;
        while (!dp[n - 1][res]) res++;

        return res;
    }
};
