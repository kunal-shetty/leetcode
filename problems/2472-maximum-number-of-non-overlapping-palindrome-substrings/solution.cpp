// 2472. Maximum Number of Non-overlapping Palindrome Substrings
// Difficulty: Hard
// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
// Runtime: 0 ms (beats —)
// Memory: 8.7 MB (beats —)
// Submitted: 2026-09-15

class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;
        int lastEnd = 0;

        for (int right = k - 1; right < n; right++) {
            int left = right - k + 1;

            bool add =
                (left >= lastEnd && isPalindrome(s, left, right)) ||
                (left > lastEnd && isPalindrome(s, left - 1, right));

            if (add) {
                count++;
                lastEnd = right + 1;
            }
        }

        return count;
    }
};
