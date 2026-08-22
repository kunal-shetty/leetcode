// 3622. Check Divisibility by Digit Sum and Product
// Difficulty: Easy
// https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/
// Runtime: 0 ms (beats —)
// Memory: 7.7 MB (beats —)
// Submitted: 2026-08-22

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int original = n;

        while (n > 0) {
            int d = n % 10;
            n /= 10;

            sum += d;
            prod *= d;
        }

        return original % (sum + prod) == 0;
    }
};
