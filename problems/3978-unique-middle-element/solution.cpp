// 3978. Unique Middle Element
// Difficulty: Easy
// https://leetcode.com/problems/unique-middle-element/
// Runtime: 0 ms (beats —)
// Memory: 31 MB (beats —)
// Submitted: 2026-07-04

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid = nums[nums.size() / 2];
        return count(nums.begin(), nums.end(), mid) == 1;
    }
};
