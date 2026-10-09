// 55. Jump Game
// Difficulty: Medium
// https://leetcode.com/problems/jump-game/
// Runtime: 0 ms (beats —)
// Memory: 52.3 MB (beats —)
// Submitted: 2026-10-09

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= end) {
                end = i;
            }
        }

        return end == 0;        
    }
};
