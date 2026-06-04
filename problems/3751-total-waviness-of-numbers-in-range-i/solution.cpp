// 3751. Total Waviness of Numbers in Range I
// Difficulty: Medium
// https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/
// Runtime: 51 ms (beats —)
// Memory: 9.4 MB (beats —)
// Submitted: 2026-06-04

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int wavy = 0;
        for (int n = num1; n <= num2; n++) {
            string s = to_string(n);
            for (int i = 1; i < s.length() - 1; i++) {
                bool peak = s[i - 1] < s[i] && s[i] > s[i + 1];
                bool valley = s[i - 1] > s[i] && s[i] < s[i + 1];
                if (valley || peak)
                    wavy++;
            }
        }
        return wavy;
    }
};
