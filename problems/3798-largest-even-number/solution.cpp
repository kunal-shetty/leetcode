// 3798. Largest Even Number
// Difficulty: Easy
// https://leetcode.com/problems/largest-even-number/
// Runtime: 0 ms (beats —)
// Memory: 8.5 MB (beats —)
// Submitted: 2026-06-06

class Solution {
public:
    string largestEven(string s) {
        if (s[s.length() - 1] == 2)
            return s;
        while (!s.empty() && s.back() == '1') {
            s.pop_back();
        }
        return s;
    }
};
