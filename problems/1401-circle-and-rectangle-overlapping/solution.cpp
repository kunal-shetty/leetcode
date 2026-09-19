// 1401. Circle and Rectangle Overlapping
// Difficulty: Medium
// https://leetcode.com/problems/circle-and-rectangle-overlapping/
// Runtime: 0 ms (beats —)
// Memory: 7.9 MB (beats —)
// Submitted: 2026-09-19

class Solution {
public:
    bool checkOverlap(int r, int cx, int cy, int x1, int y1, int x2, int y2) {
        int x = clamp(cx, x1, x2) - cx;
        int y = clamp(cy, y1, y2) - cy;

        return x * x + y * y <= r * r;
    }
};
