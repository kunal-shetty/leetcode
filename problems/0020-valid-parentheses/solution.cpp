// 20. Valid Parentheses
// Difficulty: Easy
// https://leetcode.com/problems/valid-parentheses/
// Runtime: 2 ms (beats —)
// Memory: 10.2 MB (beats —)
// Submitted: 2026-10-01

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = { {'}', '{'}, {']', '['}, {')', '('} };
        stack<int> st;
        for(auto c : s){
            if(c == '{' || c == '[' || c == '(') st.push(c);
            else {
                if(st.empty() || st.top() != map[c]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
