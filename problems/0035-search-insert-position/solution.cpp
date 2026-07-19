// 35. Search Insert Position
// Difficulty: Easy
// https://leetcode.com/problems/search-insert-position/
// Runtime: 0 ms (beats —)
// Memory: 13.6 MB (beats —)
// Submitted: 2026-07-19

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left - (left - right) / 2;
            if(target == nums[mid]) return mid;
            else if(target > nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};
