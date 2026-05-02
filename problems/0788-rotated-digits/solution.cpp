// 788. Rotated Digits
// Difficulty: Medium
// https://leetcode.com/problems/rotated-digits/
// Runtime: 0 ms (beats —)
// Memory: 7.9 MB (beats —)
// Submitted: 2026-05-02

class Solution {
public:
    bool isGood(int n) {
        bool isGood = false;
        while (n) {
            int digit = n % 10;
            if (digit == 3 || digit == 4 || digit == 7)
                return false;
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                isGood = true;
            n /= 10;
        }
        return isGood;
    }

    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (isGood(i))
                count++;
        }
        return count;
    }
};
