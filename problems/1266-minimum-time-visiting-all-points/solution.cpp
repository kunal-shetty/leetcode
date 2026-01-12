// 1266. Minimum Time Visiting All Points
// Difficulty: Easy
// https://leetcode.com/problems/minimum-time-visiting-all-points/
// Runtime: 0 ms (beats —)
// Memory: 13.8 MB (beats —)
// Submitted: 2026-01-12

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int count = 0;
        int x = 0, y = 0;
        int dx, dy;
        for(int i = 0; i < points.size() - 1; i++) {
                dx = abs(points[i + 1][0] - points[i][0]);
                dy = abs(points[i + 1][1] - points[i][1]);
            count += dx > dy ? dx : dy;
        }
        return count;
    }
};
