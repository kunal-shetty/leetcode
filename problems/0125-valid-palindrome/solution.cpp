// 125. Valid Palindrome
// Difficulty: Easy
// https://leetcode.com/problems/valid-palindrome/
// Runtime: 0 ms (beats —)
// Memory: 10.3 MB (beats —)
// Submitted: 2026-09-03

class Solution {
public:
    bool isPalindrome(string s) {

        string stripped = "";
        for (auto c : s) {
            if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c<= '9')
                stripped += tolower(c);
        }
        int l = 0, r = stripped.length() - 1;
        while (l <= r) {
            if (stripped[l] != stripped[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
