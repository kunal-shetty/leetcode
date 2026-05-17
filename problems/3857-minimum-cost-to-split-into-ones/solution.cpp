// 3857. Minimum Cost to Split into Ones
// Difficulty: Medium
// https://leetcode.com/problems/minimum-cost-to-split-into-ones/
// Runtime: 0 ms (beats —)
// Memory: 8 MB (beats —)
// Submitted: 2026-05-17

class Solution {
public:
    int minCost(int n) {
        return n * (n - 1) / 2;
    }
};
