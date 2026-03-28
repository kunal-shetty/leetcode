// 3880. Minimum Absolute Difference Between Two Values
// Difficulty: Easy
// https://leetcode.com/problems/minimum-absolute-difference-between-two-values/
// Runtime: 0 ms (beats —)
// Memory: 25.6 MB (beats —)
// Submitted: 2026-03-28

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int last1 = -1, last2 = -1, ans = 101;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) last1 = i;
            if (nums[i] == 2) last2 = i;

            if (last1 != -1 && last2 != -1) {
                int d = last1 - last2;
                if (d < 0) d = -d;
                if (d < ans) ans = d;
            }
        }
        return ans == 101 ? -1 : ans;
    }
};
