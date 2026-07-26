// 4001. Aggregate Two Time Series
// Difficulty: Medium
// https://leetcode.com/problems/aggregate-two-time-series/
// Runtime: 75 ms (beats —)
// Memory: 350.3 MB (beats —)
// Submitted: 2026-07-26

class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1,
                                            vector<vector<int>>& s2) {
        vector<vector<int>> res;
        int i = 0, j = 0, p1 = 0, p2 = 0;

        while (i < s1.size() || j < s2.size()) {
            int t;
            if (j == s2.size() || (i < s1.size() && s1[i][0] < s2[j][0])) {
                t = s1[i][0];
                i++;
            } else if (i == s1.size() || s2[j][0] < s1[i][0]) {
                t = s2[j][0];
                j++;
            } else {
                t = s1[i][0];
                i++;
                j++;
            }
            while (p1 < s1.size() && s1[p1][0] < t)
                p1++;
            while (p2 < s2.size() && s2[p2][0] < t)
                p2++;

            long long v1 = (p1 < s1.size()) ? s1[p1][1] : 0;
            long long v2 = (p2 < s2.size()) ? s2[p2][1] : 0;

            res.push_back({t, (int)(v1 + v2)});
        }
        return res;
    }
};
