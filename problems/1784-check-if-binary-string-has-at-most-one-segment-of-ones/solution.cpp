// 1784. Check if Binary String Has at Most One Segment of Ones
// Difficulty: Easy
// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
// Runtime: 0 ms (beats —)
// Memory: 8.2 MB (beats —)
// Submitted: 2026-03-06

class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '1' and s[i - 1] == '0')
                return false;
        }
        return true;
    }
};
