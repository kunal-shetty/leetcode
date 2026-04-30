// 3894. Traffic Signal Color
// Difficulty: Easy
// https://leetcode.com/problems/traffic-signal-color/
// Runtime: 0 ms (beats —)
// Memory: 7.8 MB (beats —)
// Submitted: 2026-04-30

class Solution {
public:
    string trafficSignal(int timer) {
        if(timer == 0) return "Green";
        if(timer == 30) return "Orange";
        if(timer <= 90 && timer > 30) return "Red";
        return "Invalid";
    }
};
