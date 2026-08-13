// 461. Hamming Distance
// Difficulty: Easy
// https://leetcode.com/problems/hamming-distance/
// Runtime: 0 ms (beats —)
// Memory: 7.8 MB (beats —)
// Submitted: 2026-08-13

class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};
