// 342. Power of Four
// Difficulty: Easy
// https://leetcode.com/problems/power-of-four/
// Runtime: 0 ms (beats —)
// Memory: 7.7 MB (beats —)
// Submitted: 2026-06-13

class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0 && (n & (n - 1)) == 0) && (n % 3 == 1);
    }
};
