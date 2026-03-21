// 1. Two Sum
// Difficulty: Easy
// https://leetcode.com/problems/two-sum/
// Runtime: 3 ms (beats —)
// Memory: 14.9 MB (beats —)
// Submitted: 2026-10-13

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        for (int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];
            if (idx.contains(c))
                return {i, idx[c]};
            idx[nums[i]] = i;
        }
        return {};
    }
};
