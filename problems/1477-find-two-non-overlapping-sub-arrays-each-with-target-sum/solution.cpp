// 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
// Difficulty: Medium
// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
// Runtime: 11 ms (beats —)
// Memory: 88.7 MB (beats —)
// Submitted: 2026-09-17

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int res = n + 1;
        int sum = 0;
        vector<int> dp(n + 1, n);
        for (int l = 0, r = 0; r < n; r++) {
            sum += arr[r];
            while (sum > target) {
                sum -= arr[l++];
            }
            dp[r + 1] = dp[r];
            if (sum == target) {
                res = min(res, r - l + 1 + dp[l]);
                dp[r + 1] = min(dp[r], r - l + 1);
            }
        }
        return res == n + 1 ? -1 : res;
    }
};
