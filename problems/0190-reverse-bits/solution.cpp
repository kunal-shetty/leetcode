// 190. Reverse Bits
// Difficulty: Easy
// https://leetcode.com/problems/reverse-bits/
// Runtime: 2 ms (beats —)
// Memory: 8.2 MB (beats —)
// Submitted: 2026-02-16

class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res |= (n & 1);
            n >>= 1;
        }
        return res;
    }
};
