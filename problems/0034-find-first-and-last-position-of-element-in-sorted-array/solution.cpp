// 34. Find First and Last Position of Element in Sorted Array
// Difficulty: Medium
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Runtime: 0 ms (beats —)
// Memory: 17.5 MB (beats —)
// Submitted: 2026-09-23

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        if (l == nums.size() || nums[l] != target)
            return {-1, -1};

        return {l, r};
    }
};
