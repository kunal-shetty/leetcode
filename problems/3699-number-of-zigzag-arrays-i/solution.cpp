// 3699. Number of ZigZag Arrays I
// Difficulty: Hard
// https://leetcode.com/problems/number-of-zigzag-arrays-i/
// Runtime: 255 ms (beats —)
// Memory: 11.8 MB (beats —)
// Submitted: 2026-06-23

class Solution {
public:
    const int MOD = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<int> dp(m, 1);
        for (int i = 2; i <= n; i++) {
            reverse(dp.begin(), dp.end());
            long long pref = 0;
            for (int i = 0; i < m; i++) {
                int prev = dp[i];
                dp[i] = pref;
                pref = (pref + prev) % MOD;
            }
        }
        long long ans = 0;
        for (int val : dp) {
            ans = (ans + val) % MOD;
        }
        return ans * 2 % MOD;
    }
};
