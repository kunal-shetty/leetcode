// 3983. Subsequence After One Replacement
// Difficulty: Medium
// https://leetcode.com/problems/subsequence-after-one-replacement/
// Runtime: 301 ms (beats —)
// Memory: 353.8 MB (beats —)
// Submitted: 2026-07-05

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> next((long long)(m + 1) * 26);
        for (int i = 0; i < 26; i++)
            next[m * 26 + i] = m;
        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < 26; i++) {
                next[j * 26 + i] = next[(j + 1) * 26 + i];
            }
            next[j * 26 + (t[j] - 'a')] = j;
        }

        vector<int> prev((long long)m * 26);
        if (m > 0) {
            for (int c = 0; c < 26; c++)
                prev[c] = (t[0] - 'a' == c) ? 0 : -1;
            for (int j = 1; j < m; j++) {
                for (int c = 0; c < 26; c++)
                    prev[j * 26 + c] = prev[(j - 1) * 26 + c];
                prev[j * 26 + (t[j] - 'a')] = j;
            }
        }

        vector<int> forward(n + 1);
        forward[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (forward[i - 1] > m) {
                forward[i] = m + 1;
                continue;
            }
            int pos = next[forward[i - 1] * 26 + (s[i - 1] - 'a')];
            forward[i] = (pos < m) ? pos + 1 : m + 1;
        }

        vector<int> suf(n + 1);
        suf[n] = m;
        for (int i = n - 1; i >= 0; i--) {
            if (suf[i + 1] == -1 || suf[i + 1] - 1 < 0) {
                suf[i] = -1;
                continue;
            }
            suf[i] = prev[(suf[i + 1] - 1) * 26 + (s[i] - 'a')];
        }

        if (forward[n] <= m)
            return true;

        for (int i = 0; i < n; i++) {
            if (forward[i] > m)
                break;
            if (suf[i + 1] != -1 && forward[i] < suf[i + 1])
                return true;
        }
        return false;
    }
};
