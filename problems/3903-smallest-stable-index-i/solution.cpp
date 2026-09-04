// 3903. Smallest Stable Index I
// Difficulty: Easy
// https://leetcode.com/problems/smallest-stable-index-i/
// Runtime: 0 ms (beats —)
// Memory: 30.2 MB (beats —)
// Submitted: 2026-09-04

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int maxValue = nums[i], minValue = nums[i];
            for (int j = 0; j < i; ++j) {
                maxValue = max(maxValue, nums[j]);
            }
            for (int j = i + 1; j < n; ++j) {
                minValue = min(minValue, nums[j]);
            }
            if (maxValue - minValue <= k) {
                return i;
            }
        }
        return -1;
    }
};
