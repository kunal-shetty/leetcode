// 561. Array Partition
// Difficulty: Easy
// https://leetcode.com/problems/array-partition/
// Runtime: 11 ms (beats —)
// Memory: 31.9 MB (beats —)
// Submitted: 2026-06-21

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size(); i+=2){
            sum += nums[i];
        }
        return sum;
    }
};
