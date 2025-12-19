// 2485. Find the Pivot Integer
// Difficulty: Easy
// https://leetcode.com/problems/find-the-pivot-integer/
// Runtime: 0 ms (beats —)
// Memory: 8.2 MB (beats —)
// Submitted: 2025-12-19

class Solution {
    public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        int x = sqrt(total);

        if (x * x == total)
            return x;

        return -1;
    }
};
