// 2769. Find the Maximum Achievable Number
// Difficulty: Easy
// https://leetcode.com/problems/find-the-maximum-achievable-number/
// Runtime: 0 ms (beats —)
// Memory: 9.6 MB (beats —)
// Submitted: 2026-05-31

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2 * t;
    }
};
