// 1888. Minimum Number of Flips to Make the Binary String Alternating
// Difficulty: Medium
// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
// Runtime: 11 ms (beats —)
// Memory: 14.2 MB (beats —)
// Submitted: 2026-03-07

class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int op[2] = {0, 0};

        for (int i = 0; i < n; i++)
            op[(s[i] ^ i) & 1]++;

        int res = min(op[0], op[1]);

        for (int i = 0; i < n - 1; i++) {
            op[(s[i] ^ i) & 1]--;
            op[(s[i] ^ (n + i)) & 1]++;
            res = min(res, min(op[0], op[1]));
        }

        return res;
    }
};
