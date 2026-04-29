// 3225. Maximum Score From Grid Operations
// Difficulty: Hard
// https://leetcode.com/problems/maximum-score-from-grid-operations/
// Runtime: 416 ms (beats —)
// Memory: 207.9 MB (beats —)
// Submitted: 2026-04-29

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (n == 1)
            return 0;

        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)));

        vector<vector<long long>> prevMax(n + 1, vector<long long>(n + 1, 0));

        vector<vector<long long>> sufMax(n + 1, vector<long long>(n + 1, 0));

        vector<vector<long long>> colSum(n, vector<long long>(n + 1, 0));

        for (int c = 0; c < n; c++) {
            for (int r = 1; r <= n; r++) {
                colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
            }
        }

        for (int col = 1; col < n; col++) {
            for (int curH = 0; curH <= n; curH++) {
                for (int prevH = 0; prevH <= n; prevH++) {

                    if (curH <= prevH) {
                        long long gain = colSum[col][prevH] - colSum[col][curH];

                        dp[col][curH][prevH] =
                            max(dp[col][curH][prevH], sufMax[prevH][0] + gain);
                    } else {
                        long long gain =
                            colSum[col - 1][curH] - colSum[col - 1][prevH];

                        dp[col][curH][prevH] =
                            max({dp[col][curH][prevH], sufMax[prevH][curH],
                                 prevMax[prevH][curH] + gain});
                    }
                }
            }

            for (int curH = 0; curH <= n; curH++) {

                prevMax[curH][0] = dp[col][curH][0];

                for (int prevH = 1; prevH <= n; prevH++) {
                    long long penalty =
                        (prevH > curH)
                            ? (colSum[col][prevH] - colSum[col][curH])
                            : 0;

                    prevMax[curH][prevH] = max(prevMax[curH][prevH - 1],
                                               dp[col][curH][prevH] - penalty);
                }

                sufMax[curH][n] = dp[col][curH][n];

                for (int prevH = n - 1; prevH >= 0; prevH--) {
                    sufMax[curH][prevH] =
                        max(sufMax[curH][prevH + 1], dp[col][curH][prevH]);
                }
            }
        }

        long long ans = 0;
        for (int h = 0; h <= n; h++) {
            ans = max({ans, dp[n - 1][n][h], dp[n - 1][0][h]});
        }

        return ans;
    }
};
