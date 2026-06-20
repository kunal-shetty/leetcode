// 1840. Maximum Building Height
// Difficulty: Hard
// https://leetcode.com/problems/maximum-building-height/
// Runtime: 46 ms (beats —)
// Memory: 106.8 MB (beats —)
// Submitted: 2026-06-20

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        int size = restrictions.size();

        for (int idx = 1; idx < size; idx++) {
            int gap = restrictions[idx][0] - restrictions[idx - 1][0];
            restrictions[idx][1] =
                min(restrictions[idx][1], restrictions[idx - 1][1] + gap);
        }

        for (int idx = size - 2; idx >= 0; idx--) {
            int gap = restrictions[idx + 1][0] - restrictions[idx][0];
            restrictions[idx][1] =
                min(restrictions[idx][1], restrictions[idx + 1][1] + gap);
        }

        int maxHeight = 0;

        for (int idx = 1; idx < size; idx++) {
            maxHeight = max(maxHeight, restrictions[idx][1]);

            int gap = restrictions[idx][0] - restrictions[idx - 1][0];
            int peak =
                (restrictions[idx - 1][1] + restrictions[idx][1] + gap) / 2;

            maxHeight = max(maxHeight, peak);
        }

        return maxHeight;
    }
};
