// 693. Binary Number with Alternating Bits
// Difficulty: Easy
// https://leetcode.com/problems/binary-number-with-alternating-bits/
// Runtime: 0 ms (beats —)
// Memory: 7.8 MB (beats —)
// Submitted: 2026-02-18

class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};
