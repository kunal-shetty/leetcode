// 3951. Minimum Energy to Maintain Brightness
// Difficulty: Medium
// https://leetcode.com/problems/minimum-energy-to-maintain-brightness/
// Runtime: 59 ms (beats —)
// Memory: 203.4 MB (beats —)
// Submitted: 2026-06-06

using ll = long long;

class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        ll L = intervals[0][0];
        ll R = intervals[0][1];
        int active = 0;

        for (int i = 1; i < intervals.size(); i++) {
            ll l = intervals[i][0];
            ll r = intervals[i][1];

            if (l <= R + 1)
                R = max(R, r);
            else {
                active = active + R - L + 1;
                L = l;
                R = r;
            }
        }
        active = active + R - L + 1;

        ll bulbs = (brightness + 2) / 3;
        return active * bulbs;
    }
};
