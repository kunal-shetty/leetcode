// 3774. Absolute Difference Between Maximum and Minimum K Elements
// Difficulty: Easy
// https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements/
// Runtime: 0 ms (beats —)
// Memory: 32.2 MB (beats —)
// Submitted: 2025-12-14

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0, end = 0;
        for(int i = 0; i < k; i++){
            start += nums[i];
            end += nums[nums.size() - 1 - i];
        }
        int res = start - end;
        return res > 0 ? res : -res;
    }
    
};
