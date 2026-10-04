// 4070. Minimum Rotations to Dial a Number I
// Difficulty: Easy
// https://leetcode.com/problems/minimum-rotations-to-dial-a-number-i/
// Runtime: 0 ms (beats —)
// Memory: 8.7 MB (beats —)
// Submitted: 2026-10-04

class Solution {
public:
    int minRotations(string s) {
        int curr = 0, res = 0;
        for (auto c : s) {
            int x = c - '0';
            int d = abs(x - curr);
            res += min(d, 10 - d);
            curr = x;
        }
        return res;
    }
};
