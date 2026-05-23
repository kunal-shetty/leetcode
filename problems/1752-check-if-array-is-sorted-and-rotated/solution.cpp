// 1752. Check if Array Is Sorted and Rotated
// Difficulty: Easy
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Runtime: 0 ms (beats —)
// Memory: 11.2 MB (beats —)
// Submitted: 2026-05-23

class Solution {
public:
    bool check(vector<int>& nums) {
        int invalid = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) invalid++;
        }
        return invalid <= 1;
    }
};
