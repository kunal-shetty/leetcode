// 1927. Sum Game
// Difficulty: Medium
// https://leetcode.com/problems/sum-game/
// Runtime: 4 ms (beats —)
// Memory: 14.2 MB (beats —)
// Submitted: 2026-08-23

class Solution {
public:
    bool sumGame(string s) {
        int n = s.size(), sum = 0;

        for (int i = 0; i < n; i++) {
            int val = (s[i] == '?') ? 9 : (s[i] - '0') * 2;
            sum += (i < n / 2 ? val : -val);
        }

        return sum != 0;
    }
};
