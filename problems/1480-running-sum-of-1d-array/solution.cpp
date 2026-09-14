// 1480. Running Sum of 1d Array
// Difficulty: Easy
// https://leetcode.com/problems/running-sum-of-1d-array/
// Runtime: 0 ms (beats —)
// Memory: 12.6 MB (beats —)
// Submitted: 2026-09-14

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        return partial_sum(nums.begin(), nums.end(), nums.begin()), nums;
    }
};
