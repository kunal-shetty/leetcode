// 704. Binary Search
// Difficulty: Easy
// https://leetcode.com/problems/binary-search/
// Runtime: 0 ms (beats —)
// Memory: 31.3 MB (beats —)
// Submitted: 2026-04-22

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(target == nums[mid]) return mid;
            if(target > nums[mid]) start = mid + 1;
            if(target < nums[mid]) end = mid - 1;
        }
        return -1;
    }
};
