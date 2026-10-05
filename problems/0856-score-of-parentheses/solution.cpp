// 856. Score of Parentheses
// Difficulty: Medium
// https://leetcode.com/problems/score-of-parentheses/
// Runtime: 0 ms (beats —)
// Memory: 8 MB (beats —)
// Submitted: 2026-10-05

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int res = 0;

        for(auto c : s) {
            if(c == '(') {
                st.push(res);
                res = 0;
            }
            else {
                res = st.top() + max(res * 2, 1);
                st.pop();
            }
        }

        return res;
    }
};
