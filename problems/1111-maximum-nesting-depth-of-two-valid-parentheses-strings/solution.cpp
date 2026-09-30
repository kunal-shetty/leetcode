// 1111. Maximum Nesting Depth of Two Valid Parentheses Strings
// Difficulty: Medium
// https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
// Runtime: 4 ms (beats —)
// Memory: 10.5 MB (beats —)
// Submitted: 2026-09-30

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d = 0;
        vector<int> res;
        for (char c : seq) {
            if (c == '(') {
                res.push_back(d % 2);
                d++;
            } else {
                d--;
                res.push_back(d % 2);
            }
        }
        return res;
    }
};
