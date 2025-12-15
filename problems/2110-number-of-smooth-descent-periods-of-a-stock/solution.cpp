// 2110. Number of Smooth Descent Periods of a Stock
// Difficulty: Medium
// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
// Runtime: 0 ms (beats —)
// Memory: 107.1 MB (beats —)
// Submitted: 2025-12-15

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        if (prices.empty()) return 0;

        long long result = 1; // first element
        long long len = 1;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - prices[i] == 1) {
                len++;            // extend descent
            } else {
                len = 1;          // reset
            }
            result += len;
        }

        return result;
    }
};
