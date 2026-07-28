// 3517. Smallest Palindromic Rearrangement I
// Difficulty: Medium
// https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
// Runtime: 84 ms (beats —)
// Memory: 54.1 MB (beats —)
// Submitted: 2026-07-28

class Solution {
public:
    string smallestPalindrome(string s) {
        int mid = s.length() / 2;

        sort(s.begin(), s.begin() + mid);

        for (int i = 0; i < mid; ++i) {
            s[s.size() - 1 - i] = s[i];
        }

        return s;
    }
};
