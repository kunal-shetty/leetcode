// 3975. Filter Occupied Intervals
// Difficulty: Medium
// https://leetcode.com/problems/filter-occupied-intervals/
// Runtime: 177 ms (beats —)
// Memory: 214 MB (beats —)
// Submitted: 2026-06-28

class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> merged;
        for (auto i : occupiedIntervals) {
            if (merged.empty() || 1LL * i[0] > 1LL * merged.back()[1] + 1)
                merged.push_back(i);
            else
                merged.back()[1] = max(merged.back()[1], i[1]);
        }

        vector<vector<int>> ans;
        for (auto it : merged) {
            int l = it[0], r = it[1];
            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});

                continue;
            }
            if (l < freeStart)
                ans.push_back({l, freeStart - 1});
            if (r > freeEnd)
                ans.push_back({freeEnd + 1, r});
        }
        return ans;
    }
};
