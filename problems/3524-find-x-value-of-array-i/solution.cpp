// 3524. Find X Value of Array I
// Difficulty: Medium
// https://leetcode.com/problems/find-x-value-of-array-i/
// Runtime: 133 ms (beats —)
// Memory: 151.1 MB (beats —)
// Submitted: 2026-09-21

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> res(k);
        vector<long long> dp(k);  

        for (int i = 0; i < n; i++) {
            vector<long long> newDP(k);  

            newDP[nums[i] % k]++;

            for (long long j = 0; j < k; j++) {
                newDP[j * nums[i] % k] += dp[j];
            }

            dp = move(newDP);
         
            for (int j = 0; j < k; j++) {
                res[j] += dp[j];
            }
        }

        return res;
    }
};
