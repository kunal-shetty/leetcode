// 3952. Maximum Total Value of Covered Indices
// Difficulty: Medium
// https://leetcode.com/problems/maximum-total-value-of-covered-indices/
// Runtime: 319 ms (beats —)
// Memory: 261.5 MB (beats —)
// Submitted: 2026-06-06

class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        vector<long long> dp(2, INT_MIN);
        dp[s[0] == '1'] = 0;
        for (int i = 0; i < n; i++) {
            vector<long long> newDp(2, INT_MIN);
            int next = (i + 1 < n && s[i + 1] == '1');
            for (int j = 0; j <= 1; j++) {
                if (dp[j] == INT_MIN)
                    continue;

                newDp[next] = max(newDp[next], dp[j]);

                if (j)
                    newDp[next] = max(newDp[next], dp[j] + nums[i]);
                else if (next)
                    newDp[0] = max(newDp[0], dp[j] + nums[i]);
            }
            dp = newDp;
        }
        return max(dp[0], dp[1]);
    }
};
