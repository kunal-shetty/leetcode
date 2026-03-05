// 1758. Minimum Changes To Make Alternating Binary String
// Difficulty: Easy
// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
// Runtime: 0 ms (beats —)
// Memory: 9.5 MB (beats —)
// Submitted: 2026-03-05

class Solution {
public:
    int minOperations(string s) {
        int count1 = 0, count2 = 0;
        for (int i = 0; i < s.size(); i++) {
            char s1 = (i % 2 == 0) ? '0' : '1';
            char s2 = (i % 2 == 0) ? '1' : '0';
            if (s[i] != s1) count1++;
            if (s[i] != s2) count2++;
        }
        return min(count1, count2);
    }
};
