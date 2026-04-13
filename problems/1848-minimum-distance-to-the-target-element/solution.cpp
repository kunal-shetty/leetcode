// 1848. Minimum Distance to the Target Element
// Difficulty: Easy
// https://leetcode.com/problems/minimum-distance-to-the-target-element/
// Runtime: 0 ms (beats —)
// Memory: 13.4 MB (beats —)
// Submitted: 2026-04-13

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != target) continue;
            res = min(res, abs(i - start));
        }
        return res;
    }
};
