// 76. Minimum Window Substring
// Difficulty: Hard
// https://leetcode.com/problems/minimum-window-substring/
// Runtime: 0 ms (beats —)
// Memory: 11.4 MB (beats —)
// Submitted: 2026-09-17

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> map;
        for (char c : t) map[c]++;
        int need = t.size(), l = 0, left = 0, right = INT_MAX;

        for (int r = 0; r < s.size(); r++) {
            if (map[s[r]]-- > 0) need--;
            while (!need) {
                if (r - l < right - left) left = l, right = r;
                if (map[s[l++]]++ == 0) need++;
            }
        }
        return right > s.size() ? "" : s.substr(left, right - left + 1);
    }
};
