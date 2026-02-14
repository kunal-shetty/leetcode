// 5. Longest Palindromic Substring
// Difficulty: Medium
// https://leetcode.com/problems/longest-palindromic-substring/
// Runtime: 4 ms (beats —)
// Memory: 9.2 MB (beats —)
// Submitted: 2026-02-14

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        if (n == 1) return s;

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            int left = i;
            int right = i;

            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    maxLen = len;
                    start = left;
                }
                left--;
                right++;
            }
            left = i;
            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    maxLen = len;
                    start = left;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};
