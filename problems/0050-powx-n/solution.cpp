// 50. Pow(x, n)
// Difficulty: Medium
// https://leetcode.com/problems/powx-n/
// Runtime: 0 ms (beats —)
// Memory: 8.6 MB (beats —)
// Submitted: 2026-01-31

class Solution {
public:
    double myPow(double x, int n) {

        long long exp = n; 
        double result = 1.0;

        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= x;
            }
            x *= x;
            exp /= 2;
        }

        return result;
    }
};
