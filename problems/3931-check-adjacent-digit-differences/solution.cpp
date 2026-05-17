// 3931. Check Adjacent Digit Differences
// Difficulty: Easy
// https://leetcode.com/problems/check-adjacent-digit-differences/
// Runtime: 0 ms (beats —)
// Memory: 8.7 MB (beats —)
// Submitted: 2026-05-17

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i = 0; i < s.length() - 1; i++){
            if(abs(s[i] - s[i + 1]) > 2) return false;
        }
        return true;
    }
};
