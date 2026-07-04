// 3979. Maximum Valid Pair Sum
// Difficulty: Medium
// https://leetcode.com/problems/maximum-valid-pair-sum/
// Runtime: 0 ms (beats —)
// Memory: 205.7 MB (beats —)
// Submitted: 2026-07-04

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int maxVal = INT_MIN;
        int n = nums.size();
        int best = INT_MIN;
        for(int j = k; j < n; j++){
            best = max(best, nums[j - k]);
            maxVal = max(maxVal, best + nums[j]);
        }
        return maxVal;
    }
};
