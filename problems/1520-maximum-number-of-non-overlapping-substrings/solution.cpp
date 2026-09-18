// 1520. Maximum Number of Non-Overlapping Substrings
// Difficulty: Hard
// https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
// Runtime: 15 ms (beats —)
// Memory: 23.3 MB (beats —)
// Submitted: 2026-09-18

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, s.size()), last(26, -1);
        for (int i = 0; i < s.size(); i++)
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i), last[s[i] - 'a'] = i;

        vector<pair<int, int>> ranges;
        for (int c = 0; c < 26; c++) {
            if (last[c] < 0)
                continue;
            int l = first[c], r = last[c];
            for (int i = l; i <= r; i++) {
                int d = s[i] - 'a';
                if (first[d] < l) {
                    l = -1;
                    break;
                }
                r = max(r, last[d]);
            }
            if (l >= 0)
                ranges.push_back({r, l});
        }

        sort(ranges.begin(), ranges.end());
        vector<string> res;
        int prev = -1;
        for (auto entry : ranges) {
            int r = entry.first, l = entry.second;
            if (l > prev)
                res.push_back(s.substr(l, r - l + 1)), prev = r;
        }
        return res;
    }
};
