// 3925. Concatenate Array With Reverse
// Difficulty: Easy
// https://leetcode.com/problems/concatenate-array-with-reverse/
// Runtime: 3 ms (beats —)
// Memory: 30.9 MB (beats —)
// Submitted: 2026-05-10

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> res;
        for(auto num : nums){
            res.push_back(num);
        }
        reverse(nums.begin(), nums.end());
        for(auto num : nums){
            res.push_back(num);
        }
        return res;
    }
};
