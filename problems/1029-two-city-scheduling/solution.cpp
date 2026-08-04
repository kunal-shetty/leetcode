// 1029. Two City Scheduling
// Difficulty: Medium
// https://leetcode.com/problems/two-city-scheduling/
// Runtime: 0 ms (beats —)
// Memory: 11 MB (beats —)
// Submitted: 2026-08-04

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> diff;
        int mincost = 0;

        for (auto cost : costs) {
            mincost += cost[0];
            diff.push_back(cost[1] - cost[0]);
        }

        sort(diff.begin(), diff.end());

        for (int i = 0; i < costs.size() / 2; ++i)
            mincost += diff[i];

        return mincost;
    }
};
