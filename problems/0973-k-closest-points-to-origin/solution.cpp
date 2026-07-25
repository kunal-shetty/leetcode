// 973. K Closest Points to Origin
// Difficulty: Medium
// https://leetcode.com/problems/k-closest-points-to-origin/
// Runtime: 20 ms (beats —)
// Memory: 68.5 MB (beats —)
// Submitted: 2026-07-25

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> dist; 

        for (int i = 0; i < points.size(); i++) {
            int d = points[i][0] * points[i][0] +
                    points[i][1] * points[i][1];
            dist.push_back({d, i});
        }

        sort(dist.begin(), dist.end());

        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            res.push_back(points[dist[i].second]);
        }

        return res;
    }
};
