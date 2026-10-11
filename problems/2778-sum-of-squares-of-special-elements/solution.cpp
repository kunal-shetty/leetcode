// 2778. Sum of Squares of Special Elements 
// Difficulty: Easy
// https://leetcode.com/problems/sum-of-squares-of-special-elements/
// Runtime: 0 ms (beats —)
// Memory: 40.2 MB (beats —)
// Submitted: 2026-10-11

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) 
            if (n % (i + 1) == 0)  res += nums[i] * nums[i];
        return res;
    }
};
