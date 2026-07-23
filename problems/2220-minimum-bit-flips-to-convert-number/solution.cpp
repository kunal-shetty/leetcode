// 2220. Minimum Bit Flips to Convert Number
// Difficulty: Easy
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
// Runtime: 0 ms (beats —)
// Memory: 8 MB (beats —)
// Submitted: 2026-07-23

class Solution {
public:
    int minBitFlips(int start, int goal) { return __builtin_popcount(start ^ goal); }
};
