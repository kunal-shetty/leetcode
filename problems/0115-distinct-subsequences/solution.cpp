// 115. Distinct Subsequences
// Difficulty: Hard
// https://leetcode.com/problems/distinct-subsequences/
// Runtime: 7 ms (beats —)
// Memory: 9 MB (beats —)
// Submitted: 2026-09-06

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n)
            return 0;
        vector<unsigned long long> dp(n + 1);
        dp[n] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (s[i] == t[j])
                    dp[j] = dp[j + 1] + dp[j];
            }
        }

        return dp[0];
    }
};
