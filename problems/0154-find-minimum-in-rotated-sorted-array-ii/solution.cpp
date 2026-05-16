// 154. Find Minimum in Rotated Sorted Array II
// Difficulty: Hard
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Runtime: 0 ms (beats —)
// Memory: 16.2 MB (beats —)
// Submitted: 2026-05-16

class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = INT_MAX;
        for(int num : nums){
            res= min(res, num);
        }
        return res;
    }
};
