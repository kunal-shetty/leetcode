// 1541. Minimum Insertions to Balance a Parentheses String
// Difficulty: Medium
// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// Runtime: 4 ms (beats —)
// Memory: 15.5 MB (beats —)
// Submitted: 2026-10-09

class Solution {
public:
    int minInsertions(string s) {
        int open = 0, res = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') open++;
            else {
                if (i + 1 < s.size() && s[i + 1] == ')') i++;
                else res++;
                if (open > 0) open--;
                else res++;
            }
        }

        return res+ open * 2;
    }
};
