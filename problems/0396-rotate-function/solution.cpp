// 396. Rotate Function
// Difficulty: Medium
// https://leetcode.com/problems/rotate-function/
// Runtime: 9 ms (beats —)
// Memory: 99.6 MB (beats —)
// Submitted: 2026-05-01

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, F = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += (long long)i * nums[i];
        }

        long long ans = F;

        for (int k = 1; k < n; k++) {
            F = F + sum - (long long)n * nums[n - k];
            ans = max(ans, F);
        }

        return ans;
    }
};
