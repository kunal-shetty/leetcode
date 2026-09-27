// 1190. Reverse Substrings Between Each Pair of Parentheses
// Difficulty: Medium
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Runtime: 0 ms (beats —)
// Memory: 8.7 MB (beats —)
// Submitted: 2026-09-27

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> open;
        string res;
        for (char c : s) {
            if (c == '(') {
                open.push(res.length());
            } else if (c == ')') {
                int s = open.top();
                open.pop();
                reverse(res.begin() + s, res.end());
            } else {
                res += c;
            }
        }
        return res;
    }
};
