// 22. Generate Parentheses
// Difficulty: Medium
// https://leetcode.com/problems/generate-parentheses/
// Runtime: 3 ms (beats —)
// Memory: 15.6 MB (beats —)
// Submitted: 2026-10-02

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(0, 0, "", n, res);
        return res;
    }

    void solve(int open, int close, string s, int n, vector<string>& res) {
        if(s.length() == 2 * n) 
            res.push_back(s);
        if(open < n) 
            solve(open + 1, close, s + "(", n, res);
        if(close < open) 
            solve(open, close + 1, s + ")", n, res);
        
    }
};
