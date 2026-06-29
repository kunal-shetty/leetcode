// 26. Remove Duplicates from Sorted Array
// Difficulty: Easy
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Runtime: 3 ms (beats —)
// Memory: 23.4 MB (beats —)
// Submitted: 2026-06-29

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> num(nums.begin(), nums.end());
        nums = vector<int>(num.begin(), num.end());
        return nums.size();
    }
};
