// 3644. Maximum K to Sort a Permutation
// Difficulty: Medium
// https://leetcode.com/problems/maximum-k-to-sort-a-permutation/
// Runtime: 4 ms (beats 28.6%)
// Memory: 152.5 MB (beats 98.1%)
// Submitted: 2026-10-23

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i) k &= nums[i];
        }
        return k == INT_MAX ? 0 : k;
    }
};
