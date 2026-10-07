// 301. Remove Invalid Parentheses
// Difficulty: Hard
// https://leetcode.com/problems/remove-invalid-parentheses/
// Runtime: 0 ms (beats —)
// Memory: 11.4 MB (beats —)
// Submitted: 2026-10-07

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        dfs(s, res, 0, 0, '(', ')');
        return res;
    }
    void dfs(string s, vector<string>& res, int start, int del, char open, char close) {
        int count = 0;
        for (int i = start; i < s.size(); i++) {
            if (s[i] == open) count++;
            if (s[i] == close) count--;
            if (count < 0) {
                for (int j = del; j <= i; j++)
                    if (s[j] == close && (j == del || s[j - 1] != close))
                        dfs(s.substr(0, j) + s.substr(j + 1), res, i, j, open, close);
                return;
            }
        }
        string rev(s.rbegin(), s.rend());
        if (open == '(') dfs(rev, res, 0, 0, ')', '(');
        else res.push_back(rev);
    }
};
