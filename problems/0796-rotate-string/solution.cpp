// 796. Rotate String
// Difficulty: Easy
// https://leetcode.com/problems/rotate-string/
// Runtime: 0 ms (beats —)
// Memory: 8.3 MB (beats —)
// Submitted: 2026-06-13

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string cat = s + s;
        return cat.contains(goal);
    }
};
