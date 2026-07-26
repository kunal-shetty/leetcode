// 628. Maximum Product of Three Numbers
// Difficulty: Easy
// https://leetcode.com/problems/maximum-product-of-three-numbers/
// Runtime: 11 ms (beats —)
// Memory: 31.5 MB (beats —)
// Submitted: 2026-07-26

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        return max(nums[n - 1] * nums[n - 2] * nums[n - 3],
                   nums[0] * nums[1] * nums[n - 1]);
    }
};
