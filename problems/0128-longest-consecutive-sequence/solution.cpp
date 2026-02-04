// 128. Longest Consecutive Sequence
// Difficulty: Medium
// https://leetcode.com/problems/longest-consecutive-sequence/
// Runtime: 13 ms (beats —)
// Memory: 60.2 MB (beats —)
// Submitted: 2026-02-04

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int maxLen = 1;
        int currLen = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            } 
            else if (nums[i] == nums[i - 1] + 1) {
                currLen++;
            } 
            else {
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};
