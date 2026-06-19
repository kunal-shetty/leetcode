// 482. License Key Formatting
// Difficulty: Easy
// https://leetcode.com/problems/license-key-formatting/
// Runtime: 0 ms (beats —)
// Memory: 11.1 MB (beats —)
// Submitted: 2026-06-19

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str;

        for(char c : s) {
            if(c == '-') continue;
            str += toupper(c);
        }

        string res;
        int count = 0;

        for(int i = str.size() - 1; i >= 0; i--) {
            res += str[i];
            count++;

            if(count == k && i != 0) {
                res += '-';
                count = 0;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
