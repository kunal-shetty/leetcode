// 1147. Longest Chunked Palindrome Decomposition
// Difficulty: Hard
// https://leetcode.com/problems/longest-chunked-palindrome-decomposition/
// Runtime: 8 ms (beats —)
// Memory: 14.6 MB (beats —)
// Submitted: 2026-08-13

class Solution {
public:
        int longestDecomposition(string S) {
        int res = 0, n = S.length();
        string l = "", r = "";
        for (int i = 0; i < n; ++i) {
            l = l + S[i], r = S[n - i - 1] + r;
            if (l == r)
                res++, l = "", r = "";
        }
        return res;
    }
};
