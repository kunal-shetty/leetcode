// 258. Add Digits
// Difficulty: Easy
// https://leetcode.com/problems/add-digits/
// Runtime: 0 ms (beats —)
// Memory: 8.6 MB (beats —)
// Submitted: 2026-07-19

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        if(num % 9 == 0) return 9;
        return num % 9;
    }
};
