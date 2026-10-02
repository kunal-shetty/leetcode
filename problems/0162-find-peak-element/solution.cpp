// 162. Find Peak Element
// Difficulty: Medium
// https://leetcode.com/problems/find-peak-element/
// Runtime: 0 ms (beats —)
// Memory: 12.7 MB (beats —)
// Submitted: 2026-10-02

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return max_element(nums.begin(), nums.end()) - nums.begin();
    }
};
