// 1614. Maximum Nesting Depth of the Parentheses
// Difficulty: Easy
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// Runtime: 0 ms (beats —)
// Memory: 8.2 MB (beats —)
// Submitted: 2026-09-28

class Solution {
public:
    int maxDepth(string s) {
        int res = 0, curr = 0;
        for (auto c : s) {
            if (c == '(') {
                curr++;
                res = max(curr, res);
            } else if (c == ')')
                curr--;
        }
        return res;
    }
};
