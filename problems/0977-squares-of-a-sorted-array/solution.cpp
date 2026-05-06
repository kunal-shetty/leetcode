// 977. Squares of a Sorted Array
// Difficulty: Easy
// https://leetcode.com/problems/squares-of-a-sorted-array/
// Runtime: 0 ms (beats —)
// Memory: 30.1 MB (beats —)
// Submitted: 2026-05-06

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        int start = 0, end = size - 1;
        int idx = end;
        vector<int> res(size);
        while(start <= end){
            if(abs(nums[start]) > abs(nums[end])){
                res[idx] = nums[start] * nums[start];
                start++;
            }
            else {
                res[idx] = nums[end] * nums[end];
                end--;
            }
            idx--;
        }
        return res;
    }
};
