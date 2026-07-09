// 3532. Path Existence Queries in a Graph I
// Difficulty: Medium
// https://leetcode.com/problems/path-existence-queries-in-a-graph-i/
// Runtime: 60 ms (beats —)
// Memory: 236 MB (beats —)
// Submitted: 2026-07-09

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        int compNo = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                compNo++;
            component[i] = compNo;
        }
        vector<bool> res;

        for (auto query : queries) {
            res.push_back(component[query[0]] == component[query[1]]);
        }

        return res;
    }
};
