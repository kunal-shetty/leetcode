// 1344. Angle Between Hands of a Clock
// Difficulty: Medium
// https://leetcode.com/problems/angle-between-hands-of-a-clock/
// Runtime: 0 ms (beats —)
// Memory: 8.2 MB (beats —)
// Submitted: 2026-06-18

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
        double minute = minutes * 6;

        double angle = abs(hourAngle - minute);

        return min(angle, 360 - angle);
    }
};
