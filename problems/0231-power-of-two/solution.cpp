// 231. Power of Two
// Difficulty: Easy
// https://leetcode.com/problems/power-of-two/
// Runtime: 0 ms (beats —)
// Memory: 7.8 MB (beats —)
// Submitted: 2026-08-19

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ((n - 1) & n) == 0;
    }
};
