// 4050. Minimum Days to Score Exactly N Points
// Difficulty: Medium
// https://leetcode.com/problems/minimum-days-to-score-exactly-n-points/
// Runtime: 153 ms (beats —)
// Memory: 15.4 MB (beats —)
// Submitted: 2026-09-12

class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for(int i = 1; i * (i + 1) / 2 <= n; i++){
            int t = i *(i + 1)/2;
            for(int j = t; j <=n;j++){
                if(j == t) dp[j] = min(dp[j], i);
                else dp[j] = min(dp[j], dp[j - t] + i + 1);
            }
        }
        return dp[n];
    }
};
