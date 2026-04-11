// 189. Rotate Array
// Difficulty: Medium
// https://leetcode.com/problems/rotate-array/
// Runtime: 0 ms (beats —)
// Memory: 29.6 MB (beats —)
// Submitted: 2026-04-11

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
