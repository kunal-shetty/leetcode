// 1929. Concatenation of Array
// Difficulty: Easy
// https://leetcode.com/problems/concatenation-of-array/
// Runtime: 1 ms (beats —)
// Memory: 16.9 MB (beats —)
// Submitted: 2026-02-14

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res = nums;
        for(int i = 0; i < nums.size(); i++){
            res.push_back(nums[i]);
        }
        return res;
    }
};
