// 3908. Valid Digit Number
// Difficulty: Easy
// https://leetcode.com/problems/valid-digit-number/
// Runtime: 0 ms (beats —)
// Memory: 8.7 MB (beats —)
// Submitted: 2026-05-03

class Solution {
public:
    bool validDigit(int n, int x) {
        string num = to_string(n);
        char c = x + '0';

        return num.contains(string(1, c)) && num[0] != c;
    }
};
