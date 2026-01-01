// 66. Plus One
// Difficulty: Easy
// https://leetcode.com/problems/plus-one/
// Runtime: 0 ms (beats —)
// Memory: 11.7 MB (beats —)
// Submitted: 2026-01-01

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        // If all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
