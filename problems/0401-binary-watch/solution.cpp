// 401. Binary Watch
// Difficulty: Easy
// https://leetcode.com/problems/binary-watch/
// Runtime: 2 ms (beats —)
// Memory: 9.6 MB (beats —)
// Submitted: 2026-02-17

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    string time = to_string(h) + ":";
                    if (m < 10) time += "0";
                    time += to_string(m);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};
