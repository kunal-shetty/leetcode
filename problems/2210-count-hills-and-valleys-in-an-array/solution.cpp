// 2210. Count Hills and Valleys in an Array
// Difficulty: Easy
// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
// Runtime: 0 ms (beats —)
// Memory: 11.9 MB (beats —)
// Submitted: 2026-10-05

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0, left = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                if ((nums[i] > nums[left] && nums[i] > nums[i + 1]) ||
                    (nums[i] < nums[left] && nums[i] < nums[i + 1])) {
                    res++;
                }
                left = i;
            }
        }
        return res;
    }
};
