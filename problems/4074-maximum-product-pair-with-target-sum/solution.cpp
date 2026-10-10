// 4074. Maximum Product Pair With Target Sum
// Difficulty: Easy
// https://leetcode.com/problems/maximum-product-pair-with-target-sum/
// Runtime: 1 ms (beats —)
// Memory: 31.9 MB (beats —)
// Submitted: 2026-10-10

class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size(), max = INT_MIN;
        vector<int> res = {-1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || nums[i] <= nums[j])
                    continue;
                if (nums[i] + nums[j] == target) {
                    int p = nums[i] * nums[j];
                    if (p > max) {
                        max = p;
                        res = {i, j};
                    }
                }
            }
        }
        return res;
    }
};
