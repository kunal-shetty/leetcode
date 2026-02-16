// 2119. A Number After a Double Reversal
// Difficulty: Easy
// https://leetcode.com/problems/a-number-after-a-double-reversal/
// Runtime: 0 ms (beats —)
// Memory: 7.6 MB (beats —)
// Submitted: 2026-02-16

class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num < 10) return true;
        return !(num % 10 == 0);
    }
};
