// 3794. Reverse String Prefix
// Difficulty: Easy
// https://leetcode.com/problems/reverse-string-prefix/
// Runtime: 0 ms (beats —)
// Memory: 8.9 MB (beats —)
// Submitted: 2026-07-21

class Solution {
public:
    string reversePrefix(string s, int k) {
        reverse(s.begin(), s.begin() + k);
        return s;
    }
};
