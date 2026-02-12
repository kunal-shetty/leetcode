// 3713. Longest Balanced Substring I
// Difficulty: Medium
// https://leetcode.com/problems/longest-balanced-substring-i/
// Runtime: 367 ms (beats —)
// Memory: 41.7 MB (beats —)
// Submitted: 2026-02-12

class Solution {
public:
    int longestBalanced(string s) {
        int mx = 1;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<int, int> mapp;
            int c = 0, l = 0;
            for (int j = i; j < s.size(); j++) {
                if (mapp[s[j]] == 0) c++;
                mapp[s[j]]++;
                l = max(l, mapp[s[j]]);
                int n = j - i + 1;
                if (c * l == n) mx = max(mx, n);
            }
        }
        return mx;
    }
};
