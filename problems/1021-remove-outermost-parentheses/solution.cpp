// 1021. Remove Outermost Parentheses
// Difficulty: Easy
// https://leetcode.com/problems/remove-outermost-parentheses/
// Runtime: 3 ms (beats —)
// Memory: 8.8 MB (beats —)
// Submitted: 2026-10-08

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        stack<char> st;
        for (auto c : s) {
            if (c == '(') {
                if (!st.empty()) res += c;
                st.push(c);
            } else {
                st.pop();
                if (!st.empty()) res += c;
            }
        }
        return res;
    }
};
