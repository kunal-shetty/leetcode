// 459. Repeated Substring Pattern
// Difficulty: Easy
// https://leetcode.com/problems/repeated-substring-pattern/
// Runtime: 5 ms (beats —)
// Memory: 13.5 MB (beats —)
// Submitted: 2026-09-16

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) < s.size();
    }
};
