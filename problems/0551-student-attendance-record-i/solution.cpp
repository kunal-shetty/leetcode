// 551. Student Attendance Record I
// Difficulty: Easy
// https://leetcode.com/problems/student-attendance-record-i/
// Runtime: 0 ms (beats —)
// Memory: 8.2 MB (beats —)
// Submitted: 2026-05-03

class Solution {
public:
    bool checkRecord(string s) {
        int absentCount = 0;
        for(char c : s){
            if(c == 'A') absentCount++;
        }
        bool criteria = s.contains("LLL") || absentCount >= 2;
        return !criteria;
    }
};
