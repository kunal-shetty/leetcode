// 3998. Transform Binary String Using Subsequence Sort
// Difficulty: Medium
// https://leetcode.com/problems/transform-binary-string-using-subsequence-sort/
// Runtime: 58 ms (beats —)
// Memory: 88.9 MB (beats —)
// Submitted: 2026-07-19

class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        vector<int> pref(n + 1, 0);
        int ones = 0;
        for (int i = 0; i < n; i++) {
            ones += (s[i] == '1');
            pref[i + 1] = ones;
        }
        vector<bool> ans;
        for (auto str : strs) {
            int fix = 0, q = 0;
            for (auto c : str) {
                if (c == '1')
                    fix++;
                else if (c == '?')
                    q++;
            }
            int need = ones - fix;
            if (need < 0 || need > q) {
                ans.push_back(false);
                continue;
            }
            int fixPref = 0, qPref = 0;
            bool k = true;
            for (int i = 0; i < n && k; i++) {
                if (str[i] == '1')
                    fixPref++;
                else if (str[i] == '?')
                    qPref++;
                int l = max(0, need - (q - qPref));
                int u = min(qPref, pref[i + 1] - fixPref);
                if (l > u)
                    k = false;
            }
            ans.push_back(k);
        }

        return ans;
    }
};
