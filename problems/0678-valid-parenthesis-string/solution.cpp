// 678. Valid Parenthesis String
// Difficulty: Medium
// https://leetcode.com/problems/valid-parenthesis-string/
// Runtime: 0 ms (beats —)
// Memory: 8 MB (beats —)
// Submitted: 2026-10-04

class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0;

        for (char c : s) {
            if (c == '(') left++, right++;
            else if (c == ')') left--, right--;
            else left--, right++;
            
            if (right < 0) return false; 
            if (left < 0) left = 0; 
        }

        return left == 0;
    }
};
