// 940. Distinct Subsequences II
// Difficulty: Hard
// https://leetcode.com/problems/distinct-subsequences-ii/
// Runtime: 0 ms (beats —)
// Memory: 8.8 MB (beats —)
// Submitted: 2026-09-07

class Solution {
public:
    int distinctSubseqII(string S) {
        long ends[26] = {}, mod = 1e9 + 7;
        for (char c : S)
            ends[c - 'a'] =
                accumulate(begin(ends), end(ends), 1L) % mod;
        return accumulate(begin(ends), end(ends), 0L) % mod;
    }
};
