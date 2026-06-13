// 69. Sqrt(x)
// Difficulty: Easy
// https://leetcode.com/problems/sqrtx/
// Runtime: 11 ms (beats —)
// Memory: 8.5 MB (beats —)
// Submitted: 2026-06-13

class Solution {
public:
   int mySqrt(int x) {
        if (x <= 1) return x;
        for (int i = 1; i <= x; i++) {
            long long check = (long long)i * i;
            if (check > x) return i - 1;
            if (check == x) return i;
        }
        return -1; 
    }
};
