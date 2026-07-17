// 3986. Number of Elapsed Seconds Between Two Times
// Difficulty: Easy
// https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/
// Runtime: 0 ms (beats —)
// Memory: 10.1 MB (beats —)
// Submitted: 2026-07-17

class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int hStart = stoi(startTime.substr(0, 2));
        int mStart = stoi(startTime.substr(3, 2));
        int sStart = stoi(startTime.substr(6, 2));
        int hEnd = stoi(endTime.substr(0, 2));
        int mEnd = stoi(endTime.substr(3, 2));
        int sEnd = stoi(endTime.substr(6, 2));
        return (hEnd - hStart) * 3600 + (mEnd - mStart) * 60 + (sEnd - sStart);    
    }
};
