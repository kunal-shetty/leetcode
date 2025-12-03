// 29. Divide Two Integers
// Difficulty: Medium
// https://leetcode.com/problems/divide-two-integers/
// Runtime: 2578 ms (beats —)
// Memory: 8.7 MB (beats —)
// Submitted: 2025-12-03

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case: INT_MIN / -1
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = dividend;
        long long b = divisor;

        int res = 0;

        // Quick equal checks
        if (a == b) return 1;
        if (a == -b) return -1;

        // Divisor is ±1
        if (b == 1) return a;
        if (b == -1) return -a;

        // ---------------------------
        //   Positive / Positive
        // ---------------------------
        if (a > 0 && b > 0) {
            while (a >= b) {
                a -= b;
                if (res != INT_MAX) res++;
            }
            return res;
        }

        // ---------------------------
        //   Positive / Negative
        //   (result must be negative)
        // ---------------------------
        if (a > 0 && b < 0) {
            long long bb = -b;        // absolute value
            while (a >= bb) {
                a -= bb;
                if (res != INT_MAX) res++;
            }
            return -res;
        }

        // ---------------------------
        //   Negative / Positive
        //   (result must be negative)
        // ---------------------------
        if (a < 0 && b > 0) {
            while (a <= -b) {         // move a toward 0
                a += b;               // add positive
                if (res != INT_MAX) res++;
            }
            return -res;
        }

        // ---------------------------
        //   Negative / Negative
        //   (result must be positive)
        // ---------------------------
        if (a < 0 && b < 0) {
            long long bb = -b;        // absolute value
            while (a <= -bb) {        // stop when a reaches 0 exactly
                a += bb;              // add |b|
                if (res != INT_MAX) res++;
            }
            return res;
        }

        return 0;
    }
};
