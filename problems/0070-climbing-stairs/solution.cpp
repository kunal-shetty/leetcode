// 70. Climbing Stairs
// Difficulty: Easy
// https://leetcode.com/problems/climbing-stairs/
// Runtime: 0 ms (beats —)
// Memory: 7.7 MB (beats —)
// Submitted: 2026-08-08

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};
