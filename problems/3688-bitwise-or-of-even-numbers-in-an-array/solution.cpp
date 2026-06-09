// 3688. Bitwise OR of Even Numbers in an Array
// Difficulty: Easy
// https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/
// Runtime: 0 ms (beats —)
// Memory: 24.6 MB (beats —)
// Submitted: 2026-06-09

class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int res = 0;
        for(auto num : nums){
            if(!(num & 1)) res |= num;
        }
        return res;
    }
};
