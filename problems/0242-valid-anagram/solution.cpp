// 242. Valid Anagram
// Difficulty: Easy
// https://leetcode.com/problems/valid-anagram/
// Runtime: 3 ms (beats —)
// Memory: 9.7 MB (beats —)
// Submitted: 2026-08-31

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
