// 1470. Shuffle the Array
// Difficulty: Easy
// https://leetcode.com/problems/shuffle-the-array/
// Runtime: 4 ms (beats —)
// Memory: 13.5 MB (beats —)
// Submitted: 2026-02-14

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int start = 0, end = n;
        vector<int> res;
        for(int i = 0; i < n; i++){
            res.push_back(nums[start]);
            res.push_back(nums[end]);
            start++; end++;
        }
        return res;
    }
};
