// 85. Maximal Rectangle
// Difficulty: Hard
// https://leetcode.com/problems/maximal-rectangle/
// Runtime: 24 ms (beats —)
// Memory: 17.2 MB (beats —)
// Submitted: 2026-01-11

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = (j == 0) ? 1 : dp[i][j - 1] + 1;

                    int minWidth = dp[i][j];

            
                    for (int k = i; k >= 0; k--) {
                        if (dp[k][j] == 0) break;

                        minWidth = min(minWidth, dp[k][j]);
                        int height = i - k + 1;
                        maxArea = max(maxArea, minWidth * height);
                    }
                }
            }
        }

        return maxArea;
    }
};
