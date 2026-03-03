// 136. Single Number
// Difficulty: Easy
// https://leetcode.com/problems/single-number/
// Runtime: 0 ms (beats —)
// Memory: 20.8 MB (beats —)
// Submitted: 2026-03-03

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            res = res ^ nums[i]; 
        }
        return res;
    }
};
