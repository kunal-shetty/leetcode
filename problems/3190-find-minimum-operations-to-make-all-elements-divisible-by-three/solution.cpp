// 3190. Find Minimum Operations to Make All Elements Divisible by Three
// Difficulty: Easy
// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
// Runtime: 0 ms (beats —)
// Memory: 23.3 MB (beats —)
// Submitted: 2026-05-28

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(int num : nums) if(num % 3) count++;
        return count;
    }
};
