// 2469. Convert the Temperature
// Difficulty: Easy
// https://leetcode.com/problems/convert-the-temperature/
// Runtime: 0 ms (beats —)
// Memory: 8.3 MB (beats —)
// Submitted: 2026-06-19

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {
            celsius + 273.15,
            celsius * 1.80 + 32.00
        };
    }
};
