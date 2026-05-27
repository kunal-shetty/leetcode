// 3512. Minimum Operations to Make Array Sum Divisible by K
// Difficulty: Easy
// https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
// Runtime: 0 ms (beats —)
// Memory: 45.2 MB (beats —)
// Submitted: 2026-05-27

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto num : nums) sum += num;
        return sum % k;
    }
};
