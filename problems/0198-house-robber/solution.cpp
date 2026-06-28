// 198. House Robber
// Difficulty: Medium
// https://leetcode.com/problems/house-robber/
// Runtime: 0 ms (beats —)
// Memory: 10.1 MB (beats —)
// Submitted: 2026-06-28

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        int prev2 = 0;
        int prev1 = 0;

        for (int money : nums) {
            int current = max(prev1, prev2 + money);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
