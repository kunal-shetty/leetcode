// 405. Convert a Number to Hexadecimal
// Difficulty: Easy
// https://leetcode.com/problems/convert-a-number-to-hexadecimal/
// Runtime: 0 ms (beats —)
// Memory: 7.8 MB (beats —)
// Submitted: 2026-02-04

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        unsigned int n = num;  
        string res = "";
        string hex = "0123456789abcdef";

        while (n > 0) {
            res = hex[n % 16] + res;
            n /= 16;
        }

        return res;
    }
};
