// 3701. Compute Alternating Sum
// Difficulty: Easy
// https://leetcode.com/problems/compute-alternating-sum/
// Runtime: 3 ms (beats —)
// Memory: 32.5 MB (beats —)
// Submitted: 2026-09-10

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i & 1) sum -= nums[i];
            else sum += nums[i];
        }
        return sum;
    }
};
