// 921. Minimum Add to Make Parentheses Valid
// Difficulty: Medium
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Runtime: 0 ms (beats —)
// Memory: 8.5 MB (beats —)
// Submitted: 2026-10-06

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, count = 0;
        for(char ch : s) {
            if(ch == '(') open++;
            else if(open == 0) count++;
            else open--;
        }

        return open + count;
    }
};
