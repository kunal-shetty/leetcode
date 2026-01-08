// 1458. Max Dot Product of Two Subsequences
// Difficulty: Hard
// https://leetcode.com/problems/max-dot-product-of-two-subsequences/
// Runtime: 13 ms (beats —)
// Memory: 17.7 MB (beats —)
// Submitted: 2026-01-08

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int prod = nums1[i - 1] * nums2[j - 1];
                
                dp[i][j] = max({
                    prod + max(0, dp[i - 1][j - 1]), // take both
                    dp[i - 1][j],                    // skip nums1
                    dp[i][j - 1]                     // skip nums2
                });
            }
        }
        return dp[n][m];
    }
};
