// 2439. Minimize Maximum of Array
// Difficulty: Medium
// https://leetcode.com/problems/minimize-maximum-of-array/
// Runtime: 0 ms (beats —)
// Memory: 75.1 MB (beats —)
// Submitted: 2026-08-13

class Solution {
public:
        int minimizeArrayValue(vector<int>& nums) {
        long sum = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res = max(res, (sum + i) / (i + 1));
        }
        return res;
    }
};
