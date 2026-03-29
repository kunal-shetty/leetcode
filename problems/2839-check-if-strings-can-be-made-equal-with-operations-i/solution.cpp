// 2839. Check if Strings Can be Made Equal With Operations I
// Difficulty: Easy
// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/
// Runtime: 4 ms (beats —)
// Memory: 8.3 MB (beats —)
// Submitted: 2026-03-29

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        return ((s1[0] == s2[0] && s1[2] == s2[2]) ||
                (s1[0] == s2[2] && s1[2] == s2[0])) &&
               ((s1[1] == s2[1] && s1[3] == s2[3]) ||
                (s1[1] == s2[3] && s1[3] == s2[1]));
    }
};
