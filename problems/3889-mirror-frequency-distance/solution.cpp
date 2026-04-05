// 3889. Mirror Frequency Distance
// Difficulty: Medium
// https://leetcode.com/problems/mirror-frequency-distance/
// Runtime: 26 ms (beats —)
// Memory: 58.3 MB (beats —)
// Submitted: 2026-04-05

class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freq(128, 0);

        for (char c : s) {
            freq[c]++;
        }

        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            char m = 'z' - (c - 'a');
            if (c <= m) {
                ans += abs(freq[c] - freq[m]);
            }
        }

        for (char c = '0'; c <= '9'; c++) {
            char m = '9' - (c - '0');
            if (c <= m) {
                ans += abs(freq[c] - freq[m]);
            }
        }

        return ans;
    }
};
