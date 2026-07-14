// 1446. Consecutive Characters
// Difficulty: Easy
// https://leetcode.com/problems/consecutive-characters/
// Runtime: 3 ms (beats —)
// Memory: 9.5 MB (beats —)
// Submitted: 2026-07-14

class Solution {
public:
    int maxPower(string s) {
        char c = s[0];
        int mx = 0, cnt = 0;
        for (auto ch : s) {
            if (ch == c)
                cnt++;
            else {
                c = ch;
                cnt = 1;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};
