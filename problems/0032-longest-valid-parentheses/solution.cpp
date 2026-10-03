// 32. Longest Valid Parentheses
// Difficulty: Hard
// https://leetcode.com/problems/longest-valid-parentheses/
// Runtime: 0 ms (beats —)
// Memory: 11.8 MB (beats —)
// Submitted: 2026-10-03

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int count = 0;
        st.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                    count = max(count, i - st.top());
            }
        }
        return count;
    }
};
