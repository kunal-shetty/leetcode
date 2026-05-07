// 150. Evaluate Reverse Polish Notation
// Difficulty: Medium
// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Runtime: 0 ms (beats —)
// Memory: 17.2 MB (beats —)
// Submitted: 2026-05-07

class Solution {
    long operation(long a, long b, char op){
        if(op == '+') return a + b;
        else if(op == '-') return a - b;
        else if(op == '*') return a * b;
        return a / b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;

        for(string token : tokens) {

            if(token.size() == 1 &&
               (token[0] == '+' || token[0] == '-' ||
                token[0] == '*' || token[0] == '/')) {

                long b = st.top();
                st.pop();
                long a = st.top();
                st.pop();

                long ans = operation(a, b, token[0]);

                st.push(ans);
            }
            else {
                st.push(stol(token));
            }
        }

        return st.top();
    }
};
