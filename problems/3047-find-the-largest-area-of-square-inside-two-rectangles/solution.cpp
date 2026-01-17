// 3047. Find the Largest Area of Square Inside Two Rectangles
// Difficulty: Medium
// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/
// Runtime: 106 ms (beats —)
// Memory: 59.3 MB (beats —)
// Submitted: 2026-01-17

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxArea = 0;

        for (int i = 0; i < n; i++) {
            int x1 = bottomLeft[i][0];
            int y1 = bottomLeft[i][1];
            int x2 = topRight[i][0];
            int y2 = topRight[i][1];

            for (int j = i + 1; j < n; j++) {
                int x3 = bottomLeft[j][0];
                int y3 = bottomLeft[j][1];
                int x4 = topRight[j][0];
                int y4 = topRight[j][1];

                // Intersection rectangle
                int left   = max(x1, x3);
                int right  = min(x2, x4);
                int bottom = max(y1, y3);
                int top    = min(y2, y4);

                if (left < right && bottom < top) {
                    long long side = min(
                        (long long)(right - left),
                        (long long)(top - bottom)
                    );
                    maxArea = max(maxArea, side * side);
                }
            }
        }

        return maxArea;
    }
};
