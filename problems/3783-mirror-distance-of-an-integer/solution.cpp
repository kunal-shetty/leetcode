// 3783. Mirror Distance of an Integer
// Difficulty: Easy
// https://leetcode.com/problems/mirror-distance-of-an-integer/
// Runtime: 0 ms (beats —)
// Memory: 8.6 MB (beats —)
// Submitted: 2026-04-22

class Solution {
public:
    int mirrorDistance(int n) {
        int x = n, rev = 0;
        while (x) rev = rev * 10 + x % 10, x /= 10;
        return abs(rev - n);
    }
};
