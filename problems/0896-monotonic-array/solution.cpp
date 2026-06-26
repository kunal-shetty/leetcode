// 896. Monotonic Array
// Difficulty: Easy
// https://leetcode.com/problems/monotonic-array/
// Runtime: 0 ms (beats —)
// Memory: 100.2 MB (beats —)
// Submitted: 2026-06-26

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true, decreasing = true;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] < nums[i]) decreasing = false;
            if(nums[i - 1] > nums[i]) increasing = false;
        }
        return decreasing || increasing;
    }
};
