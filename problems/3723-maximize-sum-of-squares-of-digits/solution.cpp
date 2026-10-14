// 3723. Maximize Sum of Squares of Digits
// Difficulty: Medium
// https://leetcode.com/problems/maximize-sum-of-squares-of-digits/
// Runtime: 50 ms (beats 75.6%)
// Memory: 58.4 MB (beats 84.3%)
// Submitted: 2026-10-14

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";
        if (sum > 9 * num) return res;

        while (sum >= 9) {
            res += '9';
            sum -= 9;
        }

        if (sum) res += '0' + sum;
        res.append(num - res.size(), '0');

        return res;
    }
};
