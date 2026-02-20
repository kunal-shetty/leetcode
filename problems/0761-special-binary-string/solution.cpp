// 761. Special Binary String
// Difficulty: Hard
// https://leetcode.com/problems/special-binary-string/
// Runtime: 2 ms (beats —)
// Memory: 9.5 MB (beats —)
// Submitted: 2026-02-20

class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s == "") return s;
        vector<string> ans;
        int count = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            count += s[i] == '1' ? 1 : -1;
            if (count == 0) {
                ans.push_back("1" + makeLargestSpecial(s.substr(j + 1, i - j - 1)) + "0");
                j = i + 1;
            }
        }
        sort(ans.begin(), ans.end(), greater<string>{});
        return accumulate(ans.begin(), ans.end(), ""s);
    }
};
