// 3614. Process String with Special Operations II
// Difficulty: Hard
// https://leetcode.com/problems/process-string-with-special-operations-ii/
// Runtime: 51 ms (beats —)
// Memory: 88 MB (beats —)
// Submitted: 2026-06-17

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> lengths;
        long long len = 0;

        for (auto ch : s) {
            if (ch == '*') len = max(len - 1, 0LL);
            else if (ch == '#') len *= 2;
            else if (ch != '%') len++;
            lengths.push_back(len);
        }

        if (k >= len) return '.';

        for (int i = n - 1;; i--) {
            switch (s[i]) {
            case '*':
                break;
            case '#':
                if (k >= lengths[i] / 2)
                    k -= lengths[i] / 2;
                break;
            case '%':
                k = lengths[i] - 1 - k;
                break;
            default: 
                if (lengths[i] == k + 1)
                    return s[i];
            }
        }
    }
};
