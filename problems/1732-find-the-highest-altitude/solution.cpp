// 1732. Find the Highest Altitude
// Difficulty: Easy
// https://leetcode.com/problems/find-the-highest-altitude/
// Runtime: 0 ms (beats —)
// Memory: 10.9 MB (beats —)
// Submitted: 2026-06-19

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int diff = 0;
        for(auto num : gain){
            diff += num;
            highest = max(highest, diff);
        }
        return highest;
    }
};
