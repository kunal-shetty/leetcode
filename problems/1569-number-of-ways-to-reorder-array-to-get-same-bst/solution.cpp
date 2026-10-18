// 1569. Number of Ways to Reorder Array to Get Same BST
// Difficulty: Hard
// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
// Runtime: 109 ms (beats 71.5%)
// Memory: 44.4 MB (beats 76.9%)
// Submitted: 2026-10-18

class Solution {
public:
    int MOD = 1e9 + 7;

    int choose(int n, int k) {
        vector<int> dp(k + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = min(i, k); j > 0; j--)
                dp[j] = (dp[j] + dp[j - 1]) % MOD;

        return dp[k];
    }

    long long solve(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        return choose(n - 1, left.size()) * solve(left) % MOD * solve(right) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        return (solve(nums) - 1 + MOD) % MOD;
    }
};
