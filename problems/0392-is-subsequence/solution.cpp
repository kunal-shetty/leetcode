// 392. Is Subsequence
// Difficulty: Easy
// https://leetcode.com/problems/is-subsequence/
// Runtime: 0 ms (beats —)
// Memory: 8.6 MB (beats —)
// Submitted: 2025-12-10

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr = 0;
        for(int i = 0; i < t.length(); i++) {
            if(s[ptr] == t[i]) ptr++;
        }
        return ptr == s.length();
    }
};
