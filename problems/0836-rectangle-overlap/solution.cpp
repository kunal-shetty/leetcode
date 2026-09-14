// 836. Rectangle Overlap
// Difficulty: Easy
// https://leetcode.com/problems/rectangle-overlap/
// Runtime: 0 ms (beats —)
// Memory: 9.9 MB (beats —)
// Submitted: 2026-09-14

class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
        return r1[0] < r2[2] && r2[0] < r1[2] &&
               r1[1] < r2[3] && r2[1] < r1[3];
    }
};
