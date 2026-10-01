// 169. Majority Element
// Difficulty: Easy
// https://leetcode.com/problems/majority-element/
// Runtime: 0 ms (beats —)
// Memory: 42 MB (beats —)
// Submitted: 2026-10-01

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(count == 0) candidate = nums[i];
            if(nums[i] == candidate){
                count++;
            }
            else count--;
        }
        return candidate;
    }
};
