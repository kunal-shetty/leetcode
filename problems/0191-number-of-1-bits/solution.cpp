// 191. Number of 1 Bits
// Difficulty: Easy
// https://leetcode.com/problems/number-of-1-bits/
// Runtime: 0 ms (beats —)
// Memory: 8.3 MB (beats —)
// Submitted: 2026-08-26

class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};
