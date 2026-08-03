// 1877. Minimize Maximum Pair Sum in Array
// Difficulty: Medium
// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
// Runtime: 174 ms (beats —)
// Memory: 100 MB (beats —)
// Submitted: 2026-08-03

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int sum = 0;
        while(l < r){
            sum = max(nums[l] + nums[r], sum);
            l++; r--;
        }
        return sum;
    }
};
