// 1920. Build Array from Permutation
// Difficulty: Easy
// https://leetcode.com/problems/build-array-from-permutation/
// Runtime: 0 ms (beats —)
// Memory: 20.9 MB (beats —)
// Submitted: 2026-05-28

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
       vector<int> ans; 
       for(int i = 0; i < nums.size(); i++) ans.push_back(nums[nums[i]]);
       return ans;
    }
};
