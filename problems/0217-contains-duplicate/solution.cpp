// 217. Contains Duplicate
// Difficulty: Easy
// https://leetcode.com/problems/contains-duplicate/
// Runtime: 91 ms (beats —)
// Memory: 113.3 MB (beats —)
// Submitted: 2026-08-31

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        return set.size() != nums.size();
    }
};
